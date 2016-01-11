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

static const char *setmmx[] = {
	"emms",
	"movd",
	"movq",
	"packssdw",
	"packsswb",
	"packuswb",
	"paddb",
	"paddd",
	"paddsb",
	"paddsw",
	"paddusb",
	"paddusw",
	"paddw",
	"pand",
	"pandn",
	"pcmpeqb",
	"pcmpeqd",
	"pcmpeqw",
	"pcmpgtb",
	"pcmpgtd",
	"pcmpgtw",
	"pmaddwd",
	"pmulhw",
	"pmullw",
	"por",
	"pslld",
	"psllq",
	"psllw",
	"psrad",
	"psraw",
	"psrld",
	"psrlq",
	"psrlw",
	"psubb",
	"psubd",
	"psubsb",
	"psubsw",
	"psubusb",
	"psubusw",
	"psubw",
	"punpckhbw",
	"punpckhdq",
	"punpckhwd",
	"punpcklbw",
	"punpckldq",
	"punpcklwd",
	"pxor",
	NULL
};
