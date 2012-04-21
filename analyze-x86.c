/*      analyze-x86
 *
 *      Copyright 2010 Meya Argenta <fierevere@ya.ru>
 *      Copyright 2012 Alexey Shvetsov <alexxy@gentoo.org>
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


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>

#include "analyze-x86.h"

int main(int argc, char** argv)
{   char tmp[8192];
    char *e, *s, *x;
    int ret = 0;
    char itmp[256];
    FILE *f;
    int i, ok;
    long i486=0, i586=0, i686=0, immx=0, isse=0,
         isse2=0, isse3=0, issse3=0, isse41=0,
         isse42=0, isse4a=0, i3dnow=0, i3dnowext=0,
         cpuid=0, nop=0, call=0, count=0;


    if (argc != 2) { printf("Syntax: %s <binary>\n", argv[0]); return (-1); }
    snprintf(tmp, 8191, "objdump -d %s", argv[1]);
    f = popen(tmp, "r");
    if (!f) { printf("%s\n", "unable to disassembly given binary argument"); return (-1); }

    while ( fgets ( tmp , 8191, f ) ) {
        e = strtok (tmp, "\t");
        if (e) { e = strtok (NULL, "\t");
           if (e) { e = strtok (NULL, "\t"); /* 3rd column contains instruction */
           snprintf(itmp, 255, "%s", e);
           s = strtok (itmp, " "); /* formatting as spaces */
             if (s) { x = s; /* clean, in case instruction is without args, i.e. nop */
                     while(*x) { if (*x == '\n' || *x == '\r')  *x = 0; else x++; }

             /* comparation */
            ok = 0;
              count++;
              if (!strcmp(s, "cpuid")) { cpuid++; ok = 1; }
              if (!strcmp(s, "nop")) { nop++; ok = 1; }
              if (!strcmp(s, "call")) { call++; ok = 1; }

            if (!ok)
            for (i = 0; i < NUM686; i++)
                if (!strcmp(s, set686[i])) { ok = 1; i686++ ; }

            if (!ok)
            for (i = 0; i < NUMMMX; i++)
                if (!strcmp(s, setmmx[i])) { ok = 1; immx++ ; }

            if (!ok)
            for (i = 0; i < NUMSSE; i++)
                if (!strcmp(s, setsse[i])) { ok = 1; isse++ ; }

            if (!ok)
            for (i = 0; i < NUMSSE2; i++)
                if (!strcmp(s, setsse2[i])) { ok = 1; isse2++ ; }

            if (!ok)
            for (i = 0; i < NUM486; i++)
               if (!strcmp(s, set486[i])) { ok = 1 ; i486++ ; }

            if (!ok)
            for (i = 0; i < NUM586; i++)
                if (!strcmp(s, set586[i])) { ok = 1; i586++ ; }

            if (!ok)
            for (i = 0; i < NUMSSE3; i++)
                if (!strcmp(s, setsse3[i])) { ok = 1; isse3++ ; }

            if (!ok)
            for (i = 0; i < NUMSSSE3; i++)
                if (!strcmp(s, setssse3[i])) { ok = 1; issse3++ ; }

            if (!ok)
            for (i = 0; i < NUMSSE41; i++)
                if (!strcmp(s, setsse41[i])) { ok = 1; isse41++ ; }

            if (!ok)
            for (i = 0; i < NUMSSE42; i++)
                if (!strcmp(s, setsse42[i])) { ok = 1; isse42++ ; }

            if (!ok)
            for (i = 0; i < NUMSSE4a; i++)
                if (!strcmp(s, setsse4a[i])) { ok = 1; isse4a++ ; }

            if (!ok)
            for (i = 0; i < NUM3DNOW; i++)
                if (!strcmp(s, set3dnow[i])) { ok = 1; i3dnow++ ; }

            if (!ok)
            for (i = 0; i < NUM3DNOWEXT; i++)
                if (!strcmp(s, set3dnowext[i])) { ok = 1; i3dnowext++ ; }
                    } /* instruction */
                  } /* strtok2: hex */
               } /* strtok1: address */

                                       } /* end parse */
        /* delete tmp file */
        if (f) fclose(f);
/* print statistics */
printf("instructions:\n cpuid: %lu\t nop: %lu\t call: %lu\t count: %lu\n",cpuid,nop,call,count);
if (i486) printf(" i486:\t %lu\n", i486);
if (i586) printf(" i586:\t %lu\n", i586);
if (i686) printf(" i686:\t %lu\n", i686);
if (immx) printf(" mmx:\t %lu\n", immx);
if (isse) printf(" sse:\t %lu\n", isse);
if (isse2) printf(" sse2:\t %lu\n", isse2);
if (isse3) printf(" sse3:\t %lu\n", isse3);
if (issse3) printf(" ssse3:\t %lu\n", issse3);
if (isse41) printf(" sse4.1:\t %lu\n", isse41);
if (isse42) printf(" sse4.2:\t %lu\n", isse42);
if (i3dnow) printf(" 3dnow!:\t %lu\n", i3dnow);
if (i3dnowext) printf(" 3dnowext:\t %lu\n", i3dnowext);

return 0;
}
