/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_lenght.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 13:22:20 by cchameyr          #+#    #+#             */
/*   Updated: 2016/09/05 13:22:21 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		select_lenght_help(t_specify *spec, char t)
{
	if (t == 'l')
		spec->lenght_l = true;
	else if (t == 'h')
		spec->lenght_h = true;
	else if (t == 'j')
		spec->lenght_ll = true;
	else if (t == 'z')
		spec->lenght_z = true;
	else
		return (_ERROR_);
	return (_SUCCESS_);
}

int				select_lenght(t_specify *spec, char *format, int *i)
{
	if (!ft_strncmp(format, "ll", 2))
	{
		spec->lenght_ll = true;
		*i += 1;
		return (_SUCCESS_);
	}
	else if (!ft_strncmp(format, "hh", 2))
	{
		spec->lenght_hh = true;
		*i += 1;
		return (_SUCCESS_);
	}
	else if (select_lenght_help(spec, *format))
		return (_SUCCESS_);
	return (_ERROR_);
}
