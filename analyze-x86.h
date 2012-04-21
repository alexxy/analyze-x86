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

#define NUM486 6
#define NUM586 4
#define NUM686 54
#define NUMMMX 47
#define NUMSSE 81
#define NUMSSE2 130
#define NUMSSE3 15
#define NUMSSE41 49
#define NUMSSE42 7
#define NUMSSE4a 6
#define NUM3DNOW 24
#define NUM3DNOWEXT 24
#define NUMSSSE3 16
static char set486 [NUM486] [12] = {
	"bswap",
	"cmpxchg",
	"invd",
	"invlpg",
	"wbinvd",
	"xadd"
};

static char set586 [NUM586] [12] = {
	"cmpxchg8b",
	"rdmsr",
	"rdtsc",
	"wrmsr"
};

static char set686 [NUM686] [12] = {
	"cmova",
	"cmovae",
	"cmovb",
	"cmovbe",
	"cmovc",
	"cmove",
	"cmovg",
	"cmovge",
	"cmovl",
	"cmovle",
	"cmovna",
	"cmovnae",
	"cmovnb",
	"cmovnbe",
	"cmovnc",
	"cmovne",
	"cmovng",
	"cmovnge",
	"cmovnl",
	"cmovnle",
	"cmovno",
	"cmovnp",
	"cmovns",
	"cmovnz",
	"cmovo",
	"cmovp",
	"cmovs",
	"cmovz",
	"fcmova",
	"fcmovae",
	"fcmovb",
	"fcmovbe",
	"fcmove",
	"fcmovna",
	"fcmovnae",
	"fcmovnb",
	"fcmovnbe",
	"fcmovne",
	"fcmovnu",
	"fcmovu",
	"fcomi",
	"fcomip",
	"fcompi",
	"fucomi",
	"fucomip",
	"fucompi",
	"fxrstor",
"fxsave","rdpmc","sysenter",
"sysexit","ud2","ud2a","ud2b"
};

static char setmmx [NUMMMX] [12] = {
    "emms","movd",
    "movq","packssdw",
    "packsswb","packuswb",
    "paddb","paddd",
    "paddsb","paddsw",
    "paddusb","paddusw",
    "paddw","pand",
    "pandn","pcmpeqb",
    "pcmpeqd","pcmpeqw",
    "pcmpgtb","pcmpgtd",
    "pcmpgtw","pmaddwd",
    "pmulhw","pmullw",
    "por","pslld",
    "psllq","psllw",
    "psrad","psraw",
    "psrld","psrlq",
    "psrlw","psubb",
    "psubd","psubsb",
    "psubsw","psubusb",
    "psubusw","psubw",
    "punpckhbw","punpckhdq",
    "punpckhwd","punpcklbw",
    "punpckldq","punpcklwd",
    "pxor"
};

static char setsse [NUMSSE] [12] = {
"addps","addss","andnps",
"andps","cmpeqps","cmpeqss",
"cmpleps","cmpless","cmpltps",
"cmpltss","cmpneqps","cmpneqss",
"cmpnleps","cmpnless","cmpnltps",
"cmpnltss","cmpordps","cmpordss",
"cmpps","cmpss","cmpunordps",
"cmpunordss","comiss","cvtpi2ps",
"cvtps2pi","cvtsi2ss","cvtss2si",
"cvttps2pi","cvttss2si","divps",
"divss","ldmxcsr","maskmovq",
"maxps","maxss","minps",
"minss","movaps","movhlps",
"movhps","movlhps","movlps",
"movmskps","movntps","movntq",
"movss","movups","mulps",
"mulss","orps","pavgb",
"pavgw","pextrw","pinsrw",
"pmaxsw","pmaxub","pminsw",
"pminub","pmovmskb","pmulhuw",
"prefetchnta","prefetcht0","prefetcht1",
"prefetcht2","psadbw","pshufw",
"rcpps","rcpss","rsqrtps",
"rsqrtss","sfence","shufps",
"sqrtps","sqrtss","stmxcsr",
"subps","subss","ucomiss",
"unpckhps","unpcklps","xorps"
};

static char setsse2 [NUMSSE2] [12] = {
"addpd","addsd","andnpd",
"andpd","clflush","cmpeqpd",
"cmpeqsd","cmplepd","cmplesd",
"cmpltpd","cmpltsd","cmpneqpd",
"cmpneqsd","cmpnlepd","cmpnlesd",
"cmpnltpd","cmpnltsd","cmpordpd",
"cmpordsd","cmppd","cmpsd",
"cmpunordpd","cmpunordsd","comisd",
"cvtdq2pd","cvtdq2ps","cvtpd2dq",
"cvtpd2pi","cvtpd2ps","cvtpi2pd",
"cvtps2dq","cvtps2pd","cvtsd2si",
"cvtsd2ss","cvtsi2sd","cvtss2sd",
"cvttpd2dq","cvttpd2pi","cvttps2dq",
"cvttsd2si","divpd","divsd",
"lfence","maskmovdqu","maxpd",
"maxsd","mfence","minpd",
"minsd","movapd","movd",
"movdq2q","movdqa","movdqu",
"movhpd","movlpd","movmskpd",
"movntdq","movnti","movntpd",
"movq","movq2dq","movsd",
"movupd","mulpd","mulsd",
"orpd","packssdw","packsswb",
"packuswb","paddb","paddd",
"paddq","paddsb","paddsw",
"paddusb","paddusw","paddw",
"pand","pandn","pause",
"pavgb","pavgw","pcmpeqb",
"pcmpeqd","pcmpeqw","pcmpgtb",
"pcmpgtd","pcmpgtw","pextrw",
"pinsrw","pmaddwd","pmaxsw",
"pmaxub","pminsw","pminub",
"pmovmskb","pmulhuw","pmulhw",
"pmullw","pmuludq","por",
"psadbw","pshufd","pshufhw",
"pshuflw","pslld","pslldq",
"psllq","psllw","psrad",
"psraw","psrld","psrldq",
"psrlq","psrlw","psubb",
"psubd","psubq","psubsb",
"psubsw","psubusb","psubusw",
"psubw","punpckhbw","punpckhdq",
"punpckhqdq","punpckhwd","punpcklbw",
"punpckldq"
};

static char set3dnow [NUM3DNOW] [12] = {
    "pavgusb","pfadd",
    "pfsub","pfsubr",
    "pfacc","pfcmpge",
    "pfcmpgt","pfcmpeq",
    "pfmin","pfmax",
    "pi2fw","pi2fd",
    "pf2iw","pf2id",
    "pfrcp","pfrsqrt",
    "pfmul","pfrcpit1",
    "pfrsqit1","pfrcpit2",
    "pmulhrw","pswapw",
    "femms","prefetch"
};

static char set3dnowext [NUM3DNOWEXT] [12] = {
    "pf2iw","pfnacc",
    "pfpnacc","pi2fw",
    "pswapd","maskmovq",
    "movntq","pavgb",
    "pavgw","pextrw",
    "pinsrw","pmaxsw",
    "pmaxub","pminsw",
    "pminub","pmovmskb",
    "pmulhuw","prefetchnta",
    "prefetcht0","prefetcht1",
    "prefetcht2","psadbw",
    "pshufw","sfence"
};

static char setsse3 [NUMSSE3] [12] = {
"addsubpd","addsubps",
"fisttp","fisttpl",
"fisttpll","haddpd",
"haddps","hsubpd",
"hsubps","lddqu",
"monitor","movddup",
"movshdup","movsldup",
"mwait"
};

static char setssse3 [NUMSSSE3] [12] = {
"psignb", "psignw", "psignd",
"pabsb", "pabsw", "pabsw",
"palignr", "pshufb","pmulhrsw",
"pmaddubsw","phsubw", "phsubd",
"phsubsw", "phaddw", "phaddd",
"phaddsw"
};

static char setsse41 [NUMSSE41] [12] = {
    "mpsadbw", "phminposuw",
    "pmuldq", "pmulld",
    "dpps", "dppd",
    "blendps", "blendpd",
    "blendvps", "blendvpd",
    "pblendvb", "pblendw",
    "pminsb", "pmaxsb",
    "pminuw", "pmaxuw",
    "pminud", "pmaxud",
    "pminsd", "pmaxsd",
    "roundps", "roundss",
    "roundpd", "roundsd",
    "insertps", "pinsrb",
    "pinsrd", "pinsrq",
    "extractps", "pextrb",
    "pextrw", "pextrd",
    "pextrq", "pmovsxbw",
    "pmovzxbw", "pmovsxbd",
    "pmovzxbd", "pmovsxbq",
    "pmovzxbq", "pmovsxwd",
    "pmovzxwd", "pmovsxwq",
    "pmovzxwq", "pmovsxdq",
    "pmovzxdq", "movntdqa",
    "packusdw", "pcmpeqq",
    "ptest"
};

static char setsse42 [NUMSSE42] [12] = {
     "crc32", "pcmpestri", "pcmpestrm", "pcmpistri", "pcmpistrm", "pcmpgtq", "popcnt"
};

static char setsse4a [NUMSSE4a] [12] = {
    "lzcnt", "popcnt", "extrq", "insertq", "movntsd" ,"movntss"
};
