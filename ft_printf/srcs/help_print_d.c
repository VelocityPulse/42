/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_print_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 13:24:49 by cchameyr          #+#    #+#             */
/*   Updated: 2016/09/05 13:29:40 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		put_sign(t_data *data, t_specify *spec, long long n)
{
	if (n >= 0)
	{
		if (spec->positive_sign == true)
			data->ret += write(1, "+", 1);
		else if (spec->space == true)
			data->ret += write(1, " ", 1);
	}
	else
		data->ret += write(1, "-", 1);
	return (_SUCCESS_);
}

void			before_printing_d(t_data *data, t_specify *spec, long long n)
{
	char	pad_field;
	int		sign_printed;

	sign_printed = 0;
	if (spec->positive_sign == true || spec->space == true || n < 0)
		spec->sign = 1;
	calculate_fields(spec, spec->nb_len, &spec->n_dot, &spec->n_field);
	if (spec->negative_sign == false)
	{
		pad_field = ' ';
		if (spec->dot == false && spec->zero_pad == true)
		{
			pad_field = '0';
			sign_printed = put_sign(data, spec, n);
		}
		while (--spec->n_field >= 0)
			data->ret += write(1, &pad_field, 1);
	}
	if (!sign_printed)
		put_sign(data, spec, n);
	while (--spec->n_dot >= 0)
		data->ret += write(1, "0", 1);
}

void			after_printing_d(t_data *data, t_specify *spec)
{
	if (spec->negative_sign == true)
	{
		while (--spec->n_field >= 0)
			data->ret += write(1, " ", 1);
	}
}

void			help_putnbr(t_data *data, long long n)
{
	if (n == -9223372036854775807 - 1)
	{
		ft_putnbr_ll(922337203685477580);
		write(1, "8", 1);
	}
	else
	{
		if (!(data->spec.dot == true && data->spec.dot_value == 0 && n == 0))
			ft_putnbr_ll(ft_absll(n));
		else if (data->spec.field_width > 0)
			write(1, " ", 1);
		else
			data->ret--;
	}
}
