/*
 *
 * Copyright (C) 2016 Renesas Electronics Corporation
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */
/*
 * @file cpu_info-iwg21m.c
 *
 * @brief CPU revision number file for iwaves Q7 SOMs
 *
 * @ingroup CPU revision number fetch
 */
#include <common.h>
#include <asm/io.h>

#define PRR 0xFF000044

u32 rmobile_get_cpu_type(void)
{
	u32 product;

	product = readl(PRR);

	return ((product & 0x00007F00) >> 8);
}

u32 rmobile_get_cpu_rev_integer(void)
{
	u32 product;

	product = readl(PRR);

	return (u32)(((product & 0x000000F0) >> 4) + 1);
}

u32 rmobile_get_cpu_rev_fraction(void)
{
	u32 product;

	product = readl(PRR);

	return (u32)(product & 0x0000000F);
}