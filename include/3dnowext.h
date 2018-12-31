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

static const char *set3dnowext[] = {
	"maskmovq",
	"movntq",
	"pavgb",
	"pavgw",
	"pextrw",
	"pf2iw",
	"pfnacc",
	"pfpnacc",
	"pi2fw",
	"pinsrw",
	"pmaxsw",
	"pmaxub",
	"pminsw",
	"pminub",
	"pmovmskb",
	"pmulhuw",
	"prefetchnta",
	"prefetcht0",
	"prefetcht1",
	"prefetcht2",
	"psadbw",
	"pshufw",
	"pswapd",
	"sfence",
	NULL
};
