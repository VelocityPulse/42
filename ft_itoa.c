/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 14:40:27 by cchameyr          #+#    #+#             */
/*   Updated: 2016/08/16 00:51:29 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	long	nbr;

	nbr = n;
	len = ft_nblen(nbr);
	if (!(str = ft_strnew(len)))
		return (NULL);
	if (n < 0)
		nbr = -nbr;
	while (len--)
	{
		str[len] = 48 + (nbr % 10);
		nbr = nbr / 10;
	}
	if (str[len] == '0' && str[1] != '\0')
		str[len] = '-';
	return (str);
}
