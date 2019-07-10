/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lststr2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <cchameyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 13:47:45 by cchameyr          #+#    #+#             */
/*   Updated: 2019/07/10 16:30:10 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_merge_lststr(t_lststr *list)
{
	char		*ret;
	int			len;
	t_lststr	*item;

	item = list;
	len = 0;
	while (item)
	{
		len += ft_strlen(item->str);
		item = item->next;
	}
	ret = ft_strnew(len);
	item = list;
	while (item)
	{
		ft_strcat(ret, item->str);
		item = item->next;
	}
	return ret;
}
