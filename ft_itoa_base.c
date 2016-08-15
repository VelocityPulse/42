/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 00:22:27 by                   #+#    #+#             */
/*   Updated: 2016/08/16 01:01:13 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_nblen_base(unsigned int n, int base)
{
	int		len;

	len = 1;
	while (n >= (unsigned int)base)
	{
		n /= base;
		len++;
	}
	return (len);
}

char		*ft_itoa_base(unsigned int n, int base)
{
	int				len;
	char			*str;
	static char		tab[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
	'9', 'A', 'B', 'C', 'D', 'E', 'F'};

	if (base > 16 || base <= 1)
		return (NULL);
	len = ft_nblen_base(n, base);
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (len--)
	{
		str[len] = tab[n % base];
		n = n / base;
	}
	return (str);
}
