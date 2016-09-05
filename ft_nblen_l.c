/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nblen_l.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 14:29:45 by cchameyr          #+#    #+#             */
/*   Updated: 2016/09/05 14:29:46 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nblen_l(long n)
{
	int		len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		len = ft_nblen_l(n);
		len++;
	}
	else if (n >= 10)
	{
		len = ft_nblen_l(n / 10);
		len++;
	}
	else
		len++;
	return (len);
}
