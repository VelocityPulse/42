/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnwlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 14:33:37 by cchameyr          #+#    #+#             */
/*   Updated: 2016/09/05 14:33:39 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnwlen(int *str, int len)
{
	int		ret;
	int		i;
	int		last;

	ret = 0;
	i = -1;
	while (ret < len && str[++i])
	{
		last = ft_charwlen(str[i]);
		ret += last;
		if (ret == len)
			return (len);
	}
	if (!str[i])
		return (ret);
	return (len - (4 - last));
}

/*
** this function return n valid character of the unicode string in len size
*/
