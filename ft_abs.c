/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 13:57:52 by cchameyr          #+#    #+#             */
/*   Updated: 2016/08/27 19:24:47 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		ft_abs(int a)
{
	return (a < 0 ? -a : a);
}

unsigned long long	ft_absll(long long a)
{
	return (a < 0 ? -a : a);
}

double				ft_absd(double a)
{
	return (a < 0 ? -a : a);
}
