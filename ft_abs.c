/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 14:28:09 by cchameyr          #+#    #+#             */
/*   Updated: 2016/09/05 14:28:10 by cchameyr         ###   ########.fr       */
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
