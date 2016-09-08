/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sharp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 13:22:14 by cchameyr          #+#    #+#             */
/*   Updated: 2016/09/05 13:26:00 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		sharp_specify(t_specify *spec, unsigned long long n)
{
	if (spec->sharp == true)
	{
		if (spec->base == HEXA_BASE)
		{
			if (n == 0)
				return (SHARP_NONE);
			if (spec->caps == UP_CASE)
				return (SHARP_HEXA_UP);
			else
				return (SHARP_HEXA_LO);
		}
		else if (spec->base == OCTAL_BASE)
			return (SHARP_OCTAL);
	}
	return (SHARP_NONE);
}
