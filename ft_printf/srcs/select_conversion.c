/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 13:25:17 by cchameyr          #+#    #+#             */
/*   Updated: 2016/09/05 13:27:49 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		conversion_a(t_specify *spec, char type)
{
	if (type == 'u')
	{
		spec->fct_call = &call_putbase;
		spec->base = DECIMAL_BASE;
		spec->caps = NO_CASE;
	}
	else if (type == 'U')
	{
		spec->fct_call = &call_putbase_l;
		spec->base = DECIMAL_BASE;
		spec->caps = NO_CASE;
	}
	else if (type == 'o')
	{
		spec->fct_call = &call_putbase;
		spec->base = OCTAL_BASE;
		spec->caps = NO_CASE;
	}
	else
		return (_FAULT_);
	return (_SUCCESS_);
}

static int		conversion_b(t_specify *spec, char type)
{
	if (type == 's' && spec->lenght_l == false)
		spec->fct_call = &call_putstr;
	else if (type == 'd' || type == 'i')
		spec->fct_call = &call_putnbr;
	else if (type == 'D')
		spec->fct_call = &call_putnbr_l;
	else if (type == 'c' && spec->lenght_l == false)
		spec->fct_call = &call_putchar;
	else if (type == 'x')
	{
		spec->fct_call = &call_putbase;
		spec->base = HEXA_BASE;
		spec->caps = LO_CASE;
	}
	else if (type == 'X')
	{
		spec->fct_call = &call_putbase;
		spec->base = HEXA_BASE;
		spec->caps = UP_CASE;
	}
	else
		return (_FAULT_);
	return (_SUCCESS_);
}

static int		conversion_c(t_specify *spec, char type)
{
	if ((type == 'S') || (type == 's' && spec->lenght_l == true))
		spec->fct_call = &call_putwstr;
	else if (type == 'C' || (type == 'c' && spec->lenght_l == true))
		spec->fct_call = &call_putwchar;
	else if (type == '%')
		spec->fct_call = &call_percent;
	else if (type == 'p')
		spec->fct_call = &call_putpointer;
	else if (type == 'O')
	{
		spec->fct_call = &call_putbase_l;
		spec->base = OCTAL_BASE;
		spec->caps = NO_CASE;
	}
	else
		return (_FAULT_);
	return (_SUCCESS_);
}

int				select_conversion(t_specify *spec, char type)
{
	if (conversion_a(spec, type) ||
		conversion_b(spec, type) ||
		conversion_c(spec, type))
	{
		spec->type = type;
		return (_SUCCESS_);
	}
	return (_FAULT_);
}
