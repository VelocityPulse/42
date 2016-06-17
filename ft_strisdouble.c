/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisdouble.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 12:52:24 by cchameyr          #+#    #+#             */
/*   Updated: 2016/06/17 13:53:03 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strisdouble(char *str)
{
	int		i;
	int		dot;

	if (!str)
		return (0);
	i = -1;
	dot = 0;
	while (str[++i])
	{
		if (ft_isdigit(str[i]))
			;
		else if (str[i] == '.')
		{
			if (dot == 0)
				dot++;
			else
				return (0);
		}
		else
			return (0);
	}
	return (1);
}
