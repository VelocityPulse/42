/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 13:22:31 by cchameyr          #+#    #+#             */
/*   Updated: 2016/11/29 13:27:19 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned short		ft_bswap16(unsigned short value)
{
	return ((value >> 8) | (value << 8));
}

unsigned int		ft_bswap32(unsigned int value)
{
	value = (value & 0x0000FFFF) << 16 | (value & 0xFFFF0000) >> 16;
	return ((value & 0x00FF00FF) >> 8 | (value & 0xFF00FF00) << 8);
}
