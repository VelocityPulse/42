/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 13:47:45 by cchameyr          #+#    #+#             */
/*   Updated: 2016/10/25 15:49:58 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_lstline_del(t_lstline **begin)
{
	t_lstline	*list;

	list = *begin;
	while (list)
	{
		*begin = list->next;
		ft_memdel((void **)&list->line);
		ft_memdel((void **)&list);
		list = *begin;
	}
	*begin = NULL;
}

static t_lstline	*ft_new_lstline(char *line)
{
	t_lstline	*list;

	list = (t_lstline *)ft_memalloc(sizeof(t_lstline));
	list->next = NULL;
	list->line = line;
	return (list);
}

void				ft_print_lstline(t_lstline *list)
{
	while (list)
	{
		ft_printf("%s\n", list->line);
		list = list->next;
	}
}

void				ft_add_lstline(t_lstline **begin, char *line)
{
	t_lstline	*list;

	if (*begin == NULL)
		*begin = ft_new_lstline(line);
	else
	{
		list = *begin;
		while (list->next)
			list = list->next;
		list->next = ft_new_lstline(line);
	}
}
