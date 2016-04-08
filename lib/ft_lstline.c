/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 13:47:45 by cchameyr          #+#    #+#             */
/*   Updated: 2016/04/08 22:34:37 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstline_del(t_lstline *begin)
{
	t_lstline	*temp1;
	t_lstline	*temp2;

	if (begin)
	{
		temp1 = begin;
		while (temp1)
		{
			temp2 = temp1->next;
			ft_memdel((void **)&temp1);
			temp1 = temp2;
		}
		begin = NULL;
	}
}

t_lstline	*ft_new_lstline(void)
{
	t_lstline	*list;

	list = (t_lstline *)ft_memalloc(sizeof(t_lstline));
	list->next = NULL;
	list->line = NULL;
	return (list);
}

t_lstline	*ft_add_list(t_lstline *begin, char *line)
{
	t_lstline	*list;

	if (!(begin))
	{
		begin = ft_new_lstline();
		begin->line = line;
		return (begin);
	}
	list = begin;
	while (list->next)
		list = list->next;
	list->next = ft_new_lstline();
	list = list->next;
	list->line = line;
	return (begin);
}
