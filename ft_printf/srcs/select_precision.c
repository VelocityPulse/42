/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 13:30:52 by cchameyr          #+#    #+#             */
/*   Updated: 2016/09/05 13:30:53 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		help_dot(t_data *d, t_specify *spec, int index1, int *i)
{
	int		value;

	value = va_arg(*d->ap, int);
	*i += 1 - index1;
	if (value < 0)
	{
		spec->dot = false;
		spec->dot_value = 0;
		return ;
	}
	spec->dot_value = value;
}

static void		select_dot(t_data *d, t_specify *spec, char *format, int *i)
{
	int		index1;

	index1 = 0;
	spec->dot = true;
	if (format[index1] == '0')
		*i += ++index1;
	if (ft_isdigit(format[index1]))
	{
		spec->dot_value = ft_atoi(&format[index1]);
		*i += ft_nblen(spec->dot_value) - index1;
		return ;
	}
	else if (format[index1] == '*')
	{
		help_dot(d, spec, index1, i);
		return ;
	}
	spec->dot_value = 0;
}

static void		select_field_width(t_data *d, t_specify *spec, char *f, int *i)
{
	if (*f == '0')
		spec->zero_pad = true;
	else if (*f >= '1' && *f <= '9')
	{
		spec->field_width = ft_atoi(f);
		if (spec->field_width > 9)
			*i += ft_nblen(spec->field_width) - 1;
	}
	else if (*f == '*')
	{
		spec->field_width = va_arg(*d->ap, int);
		if (spec->field_width < 0)
		{
			spec->field_width = -spec->field_width;
			spec->negative_sign = true;
		}
	}
}

int				select_precision(t_data *data, char *format, int *i)
{
	t_specify	*spec;

	spec = &data->spec;
	if (*format == '.' && format[1] != 0)
		select_dot(data, spec, &format[1], i);
	else if (ft_isdigit(*format) || *format == '*')
		select_field_width(data, spec, format, i);
	else
		return (_ERROR_);
	return (_SUCCESS_);
}
