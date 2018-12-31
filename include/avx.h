/*      analyze-x86
 *
 *      Copyright 2016 Ivan Shapovalov <intelfx100@gmail.com>
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

static const char *setavx[] = {
	"vbroadcastss",
	"vbroadcastsd",
	"vbroadcastf128",
	"vinsertf128",
	"vextractf128",
	"vmaskmovps",
	"vmaskmovpd",
	"vpermilps",
	"vpermilpd",
	"vperm2f128",
	"vzeroall",
	"vzeroupper",
	NULL
};

static const char *setavx2[] = {
	"vpbroadcastb",
	"vpbroadcastw",
	"vpbroadcastd",
	"vpbroadcastq",
	"vbroadcasti128",
	"vinserti128",
	"vextracti128",
	"vgatherdpd",
	"vgatherqpd",
	"vgatherdps",
	"vgatherqps",
	"vpgatherdd",
	"vpgatherdq",
	"vpgatherqd",
	"vpgatherqq",
	"vpmasqmovd",
	"vpmasqmovq",
	"vperms",
	"vpermd",
	"vpermpd",
	"vpermpq",
	"vperm2i128",
	"vpblendd",
	"vpsllvd",
	"vpsllvq",
	"vpsrlvd",
	"vpsrlvq",
	"vpsravd",
	NULL
};
