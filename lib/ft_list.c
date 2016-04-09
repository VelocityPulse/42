/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 15:11:03 by aperraul          #+#    #+#             */
/*   Updated: 2016/04/09 12:36:17 by cchameyr         ###   ########.fr       */
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

t_lstline	*ft_add_lstline(t_lstline *begin, char *line)
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
