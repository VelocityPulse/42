/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 13:22:41 by cchameyr          #+#    #+#             */
/*   Updated: 2016/09/05 13:37:37 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			call_putnbr(t_data *data)
{
	long long	n;
	t_specify	*spec;

	spec = &data->spec;
	if (spec->lenght_z == true)
		n = va_arg(*data->ap, size_t);
	else if (spec->lenght_ll == true)
		n = va_arg(*data->ap, long long);
	else if (spec->lenght_l == true)
		n = va_arg(*data->ap, long);
	else if (spec->lenght_h == true)
		n = (short)va_arg(*data->ap, long long);
	else if (spec->lenght_hh == true)
		n = (char)va_arg(*data->ap, long long);
	else
		n = va_arg(*data->ap, int);
	spec->nb_len = ft_nblen_ll(n) - (n < 0 ? 1 : 0);
	data->ret += spec->nb_len;
	before_printing_d(data, spec, n);
	help_putnbr(data, n);
	after_printing_d(data, spec);
}

/*
** valid flags :
** h hh z ll l
*/
