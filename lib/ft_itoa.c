/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <cchameyr@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 03:20:13 by cchameyr          #+#    #+#             */
/*   Updated: 2015/11/30 14:27:40 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_itoa_len(long n)
{
	int len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		len = ft_itoa_len(n);
		len++;
	}
	else if (n >= 10)
	{
		len = ft_itoa_len(n / 10);
		len++;
	}
	else
		len++;
	return (len);
}

char		*ft_itoa(int n)
{
	int		len;
	char	*str;
	long	nbr;

	nbr = n;
	len = ft_itoa_len(nbr);
	str = (char *)malloc(sizeof(char *) * (len + 1));
	str[len] = '\0';
	if (n < 0)
		nbr = -nbr;
	while (len)
	{
		len--;
		str[len] = 48 + (nbr % 10);
		nbr = nbr / 10;
	}
	if (str[len] == '0' && str[1] != '\0')
		str[len] = '-';
	return (str);
}
