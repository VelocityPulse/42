/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_brotate32_64.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <cchameyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 13:47:34 by cchameyr          #+#    #+#             */
/*   Updated: 2019/07/19 17:08:33 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		ft_b32rotate_left(unsigned int value, int offset)
{
	return ((value << offset) | (value >> (32 - offset)));
}

unsigned int		ft_b32rotate_right(unsigned int value, int offset)
{
	return ((value >> offset) | (value << (32 - offset)));
}

unsigned long int	ft_b64rotate_left(unsigned long int value, int offset)
{
	return ((value << offset) | (value >> (64 - offset)));
}

unsigned long int	ft_b64rotate_right(unsigned long int value, int offset)
{
	return ((value >> offset) | (value << (64 - offset)));
}
