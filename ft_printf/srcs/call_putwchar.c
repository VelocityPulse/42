/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putwchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 13:25:02 by cchameyr          #+#    #+#             */
/*   Updated: 2016/09/05 13:25:03 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		before_printing_wc(t_data *data, t_specify *spec)
{
	char	pad_field;

	spec->n_field = spec->field_width - spec->nb_len;
	if (spec->negative_sign == false)
	{
		pad_field = ' ';
		if (spec->zero_pad == true)
			pad_field = '0';
		while (--spec->n_field >= 0)
			data->ret += write(1, &pad_field, 1);
	}
}

static void		after_printing_wc(t_data *data, t_specify *spec)
{
	if (spec->negative_sign == true)
	{
		while (--spec->n_field >= 0)
			data->ret += write(1, " ", 1);
	}
}

void			call_putwchar(t_data *data)
{
	unsigned int	c;

	c = va_arg(*data->ap, unsigned int);
	data->spec.nb_len = ft_charwlen(c);
	data->ret += data->spec.nb_len;
	before_printing_wc(data, &data->spec);
	ft_putwchar(c);
	after_printing_wc(data, &data->spec);
}
