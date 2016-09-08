/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 13:22:49 by cchameyr          #+#    #+#             */
/*   Updated: 2016/09/05 13:22:50 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	call_putstr(t_data *data)
{
	char		*str;
	t_specify	*spec;

	spec = &data->spec;
	str = va_arg(*data->ap, char *);
	if (!str)
		str = "(null)";
	spec->nb_len = ft_strlen(str);
	if (spec->dot == true && spec->dot_value < spec->nb_len)
		spec->nb_len = spec->dot_value;
	before_printing_s(data, spec);
	data->ret += ft_putnstr(str, spec->nb_len);
	after_printing_s(data, spec);
}
