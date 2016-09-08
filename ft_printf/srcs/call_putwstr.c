/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putwstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 13:24:32 by cchameyr          #+#    #+#             */
/*   Updated: 2016/09/05 13:28:02 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			call_putwstr(t_data *data)
{
	int			*str;
	t_specify	*spec;

	spec = &data->spec;
	str = va_arg(*data->ap, int *);
	if (!str)
		str = L"(null)";
	data->spec.nb_len = ft_strwlen(str);
	if (spec->dot == true && spec->dot_value < spec->nb_len)
		spec->nb_len = ft_strnwlen(str, spec->dot_value);
	before_printing_s(data, &data->spec);
	data->ret += ft_putnwstr(str, spec->nb_len);
	after_printing_s(data, &data->spec);
}
