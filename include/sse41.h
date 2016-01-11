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

static const char *setsse41[] = {
	"blendpd",
	"blendps",
	"blendvpd",
	"blendvps",
	"dppd",
	"dpps",
	"extractps",
	"insertps",
	"movntdqa",
	"mpsadbw",
	"packusdw",
	"pblendvb",
	"pblendw",
	"pcmpeqq",
	"pextrb",
	"pextrd",
	"pextrq",
	"pextrw",
	"phminposuw",
	"pinsrb",
	"pinsrd",
	"pinsrq",
	"pmaxsb",
	"pmaxsd",
	"pmaxud",
	"pmaxuw",
	"pminsb",
	"pminsd",
	"pminud",
	"pminuw",
	"pmovsxbd",
	"pmovsxbq",
	"pmovsxbw",
	"pmovsxdq",
	"pmovsxwd",
	"pmovsxwq",
	"pmovzxbd",
	"pmovzxbq",
	"pmovzxbw",
	"pmovzxdq",
	"pmovzxwd",
	"pmovzxwq",
	"pmuldq",
	"pmulld",
	"ptest",
	"roundpd",
	"roundps",
	"roundsd",
	"roundss",
	NULL
};
