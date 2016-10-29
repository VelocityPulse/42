/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 13:47:45 by cchameyr          #+#    #+#             */
/*   Updated: 2016/10/29 14:31:51 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

void				ft_supp_lstline(t_lstline **begin)
{
	t_lstline	*list;
	t_lstline	*temp;

	if (*begin == NULL)
		return ;
	list = *begin;
	if (list->next == NULL)
	{
		ft_lstline_del(begin);
		return ;
	}
	while (list->next)
	{
		temp = list;
		list = list->next;
	}
	ft_lstline_del(&temp->next);
}
