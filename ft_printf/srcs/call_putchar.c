/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 13:30:25 by cchameyr          #+#    #+#             */
/*   Updated: 2016/09/05 13:30:27 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			call_putchar(t_data *data)
{
	unsigned char	c;

	c = (unsigned char)va_arg(*data->ap, int);
	before_printing_c(data, &data->spec);
	data->ret += write(1, &c, 1);
	after_printing_c(data, &data->spec);
}
