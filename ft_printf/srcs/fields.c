/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fields.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 13:24:15 by cchameyr          #+#    #+#             */
/*   Updated: 2016/09/05 13:24:16 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	calculate_fields(t_specify *spec, int nblen, int *nd, int *nf)
{
	*nd = spec->dot_value - nblen;
	if (*nd < 0)
		*nd = 0;
	*nf = (spec->field_width - nblen) - spec->sign - *nd;
}
