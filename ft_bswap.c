/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <cchameyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 13:22:31 by cchameyr          #+#    #+#             */
/*   Updated: 2019/07/22 12:22:02 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char		ft_bswap8(unsigned char value)
{
	return ((value >> 4) | (value << 4));
}

unsigned short		ft_bswap16(unsigned short value)
{
	return ((value >> 8) | (value << 8));
}

unsigned int		ft_bswap32(unsigned int value)
{
	return (ft_bswap16(value & 0xFFFF) << 16 | (ft_bswap16(value >> 16)));
}

unsigned long int	ft_bswap64(unsigned long int value)
{
	value = ((value << 8) & 0xFF00FF00FF00FF00ULL) |
		((value >> 8) & 0x00FF00FF00FF00FFULL);
	value = ((value << 16) & 0xFFFF0000FFFF0000ULL) |
		((value >> 16) & 0x0000FFFF0000FFFFULL);
	return (value << 32) | (value >> 32);
}
