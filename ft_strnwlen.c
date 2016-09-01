/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnwlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 16:44:16 by                   #+#    #+#             */
/*   Updated: 2016/09/01 17:48:29 by                  ###   ########.fr       */
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
