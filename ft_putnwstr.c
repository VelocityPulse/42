/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnwstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 14:25:49 by cchameyr          #+#    #+#             */
/*   Updated: 2016/09/05 14:25:50 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnwstr(int *str, int len)
{
	int		ret;
	int		i;

	ret = 0;
	i = -1;
	while (ret < len && str[++i])
		ret += ft_putnwchar(str[i], len - ret);
	return (ret);
}
