/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 13:22:31 by cchameyr          #+#    #+#             */
/*   Updated: 2016/11/29 15:52:33 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned short		ft_bswap16(unsigned short value)
{
	return ((value >> 8) | (value << 8));
}

unsigned int		ft_bswap32(unsigned int value)
{
	return (ft_bswap16(value & 0xFFFF) << 16 | (ft_bswap16(value >> 16)));
}
