/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_brotate8_16.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <cchameyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 13:47:34 by cchameyr          #+#    #+#             */
/*   Updated: 2019/07/19 17:09:26 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	ft_b8rotate_left(unsigned char value, int offset)
{
	return ((value << offset) | (value >> (8 - offset)));
}

unsigned char	ft_b8rotate_right(unsigned char value, int offset)
{
	return ((value >> offset) | (value << (8 - offset)));
}

unsigned short	ft_b16rotate_left(unsigned short value, int offset)
{
	return ((value << offset) | (value >> (16 - offset)));
}

unsigned short	ft_b16rotate_right(unsigned short value, int offset)
{
	return ((value >> offset) | (value << (16 - offset)));
}
