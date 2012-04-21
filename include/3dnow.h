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

#define NUM3DNOW 24

static char set3dnow [NUM3DNOW] [12] = {
	"femms",
	"pavgusb",
	"pf2id",
	"pf2iw",
	"pfacc",
	"pfadd",
	"pfcmpeq",
	"pfcmpge",
	"pfcmpgt",
	"pfmax",
	"pfmin",
	"pfmul",
	"pfrcp",
	"pfrcpit1",
	"pfrcpit2",
	"pfrsqit1",
	"pfrsqrt",
	"pfsub",
	"pfsubr",
	"pi2fd",
	"pi2fw",
	"pmulhrw",
	"prefetch",
	"pswapw",
};
