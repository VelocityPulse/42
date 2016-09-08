/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putbase_l.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 13:22:29 by cchameyr          #+#    #+#             */
/*   Updated: 2016/09/05 13:43:57 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		select_cast(t_data *d, t_specify *spec, unsigned long long *n)
{
	if (spec->lenght_ll == true)
		*n = va_arg(*d->ap, long long);
	else if (spec->lenght_z == true)
		*n = va_arg(*d->ap, size_t);
	else
		*n = va_arg(*d->ap, unsigned long long);
}

void			call_putbase_l(t_data *data)
{
	unsigned long long	n;
	t_specify			*spec;
	char				*str;

	spec = &data->spec;
	select_cast(data, spec, &n);
	spec->n = n;
	str = ft_itoa_base_ll(n, spec->base);
	if (spec->caps == LO_CASE)
		ft_lowerstr(str);
	spec->nb_len = ft_strlen(str);
	spec->sharp_mode = sharp_specify(spec, n);
	before_printing_b(data, spec);
	if (!(spec->dot == true && spec->dot_value == 0 && n == 0))
		data->ret += write(1, str, spec->nb_len);
	after_printing_d(data, spec);
	ft_memdel((void **)&str);
}

/*
** valid flags :
** ll z
*/
