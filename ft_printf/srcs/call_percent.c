/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 13:22:04 by cchameyr          #+#    #+#             */
/*   Updated: 2016/09/05 13:22:06 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	call_percent(t_data *data)
{
	before_printing_c(data, &data->spec);
	data->ret += write(1, "%", 1);
	after_printing_c(data, &data->spec);
}
