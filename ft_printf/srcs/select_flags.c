/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 13:25:32 by cchameyr          #+#    #+#             */
/*   Updated: 2016/09/05 13:25:33 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		select_flags(t_specify *spec, char type)
{
	if (type == '#')
		spec->sharp = true;
	else if (type == '+')
		spec->positive_sign = true;
	else if (type == '-')
		spec->negative_sign = true;
	else if (type == ' ')
		spec->space = true;
	else
		return (_ERROR_);
	return (_SUCCESS_);
}
