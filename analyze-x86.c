/*      analyze-x86
 *
 *      Copyright 2010 Meya Argenta <fierevere@ya.ru>
 *      Copyright 2012 Alexey Shvetsov <alexxy@gentoo.org>
 *      Copyright 2016 Ivan Shapovalov <intelfx@intelfx.name>
 *
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *      MA 02110-1301, USA.
 */

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>
#include <inttypes.h>
#include <stdbool.h>
#include <ctype.h>

#include "analyze-x86.h"

static const char *setcpuid[] = { "cpuid", NULL };
static const char *setnop[] = { "nop", NULL };
static const char *setcall[] = { "call", NULL };

struct insn_class
{
	const char *name;
	const char **insns;
	uint64_t count;
} classes[] = {
	{ .name = "cpuid", .insns = setcpuid },
	{ .name = "nop", .insns = setnop },
	{ .name = "call", .insns = setcall },
	{ .name = "i486", .insns = set486 },
	{ .name = "i586", .insns = set586 },
	{ .name = "i686", .insns = set686 },
	{ .name = "3dnow!", .insns = set3dnow },
	{ .name = "3dnowext", .insns = set3dnowext },
	{ .name = "mmx", .insns = setmmx },
	{ .name = "sse", .insns = setsse },
	{ .name = "sse2", .insns = setsse2 },
	{ .name = "sse3", .insns = setsse3 },
	{ .name = "ssse3", .insns = setssse3 },
	{ .name = "sse4.1", .insns = setsse41 },
	{ .name = "sse4.2", .insns = setsse42 },
	{ .name = "sse4a", .insns = setsse4a },
	{ .name = "aes", .insns = setaes },
	{ .name = "avx", .insns = setavx },
	{ .name = "avx2", .insns = setavx2 },
	{ }
};

#define log(fmt, ...) fprintf(stderr, fmt "\n", ## __VA_ARGS__)

#define _cleanup_(x) __attribute__((cleanup(x)))
static inline void fclosep(FILE **arg) { if (*arg) fclose(*arg); }
static inline void freep(void *arg) { if (*(void **)arg) free(*(void **)arg); }

static inline bool strword(const char *word, const char *line)
{
	char c_word, c_line;

	for (;;) {
		c_word = *word++;
		c_line = *line++;
		if (!c_word && (!c_line || isspace(c_line))) {
			return true;
		}
		if (c_word != c_line) {
			return false;
		}
	}
}

int main(int argc, char **argv)
{
	int r;

	if (argc != 2) {
		log("This program expects one argument.");
		log("Syntax: %s <binary>", argv[0]);
		return 1;
	}

	char *binary = argv[1];

	_cleanup_(freep) char *objdump_cmdline = NULL;
	asprintf(&objdump_cmdline, "exec objdump -d '%s' -M intel,intel-mnemonic 2>/dev/null", binary);
	assert(objdump_cmdline);

	_cleanup_(fclosep) FILE *objdump_stdout = popen(objdump_cmdline, "r");
	if (objdump_stdout == NULL) {
		log("popen(\"%s\") failed: %m", objdump_cmdline);
		return 1;
	}

	char line[256], *ptr;
	uint64_t insn_count = 0;
	while (fgets(line, sizeof(line), objdump_stdout) != NULL) {

		ptr = strtok(line, "\t"); /* address */
		if (ptr == NULL) continue;

		ptr = strtok(NULL, "\t"); /* opcode */
		if (ptr == NULL) continue;

		ptr = strtok(NULL, "\t"); /* insn and operands */
		if (ptr == NULL) continue;

		/* don't bother cutting off the operands and comments -- we only compare prefixes below */

		++insn_count;

		for (struct insn_class *c = classes; c->insns != NULL; ++c) {
			for (const char **i = c->insns; *i != NULL; ++i) {
				if (strword(*i, ptr)) {
					++c->count;
					goto done;
				}
			}
		}
done:;
	}

	if (ferror(objdump_stdout)) {
		log("I/O error reading objdump output: %m");
		return 1;
	}

	/* print statistics */
	if (insn_count == 0)
		return 0;

	for (struct insn_class *c = classes; c->name != NULL; ++c) {
		if (c->count > 0) {
			printf("%s\t%s\t%"PRIu64"\n", binary, c->name, c->count);
		}
	}

	printf("%s\ttotal\t%"PRIu64"\n", binary, insn_count);

	return 0;
}
