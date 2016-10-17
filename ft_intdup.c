/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 16:52:21 by cchameyr          #+#    #+#             */
/*   Updated: 2016/10/17 16:56:18 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_intdup(const int *i1, int len)
{
	int		*i2;

	if (!(i2 = (int *)ft_memalloc(sizeof(int) * (len + 1))))
		return (NULL);
	while (len)
	{
		i2[len] = i1[len];
		len--;
	}
	return (i2);
}
