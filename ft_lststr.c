/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lststr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <cchameyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 13:47:45 by cchameyr          #+#    #+#             */
/*   Updated: 2019/07/10 14:51:53 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_lststr	*ft_new_lststr(char *str)
{
	t_lststr	*list;

	list = (t_lststr *)ft_memalloc(sizeof(t_lststr));
	list->next = NULL;
	list->str = str;
	return (list);
}

void				ft_print_lststr(t_lststr *list)
{
	while (list)
	{
		ft_printf("%s\n", list->str);
		list = list->next;
	}
}

void				ft_add_lststr(t_lststr **begin, char *str)
{
	t_lststr	*list;

	if (*begin == NULL)
		*begin = ft_new_lststr(str);
	else
	{
		list = *begin;
		while (list->next)
			list = list->next;
		list->next = ft_new_lststr(str);
	}
}

void				ft_lststr_del(t_lststr **begin)
{
	t_lststr	*list;

	list = *begin;
	while (list)
	{
		*begin = list->next;
		ft_memdel((void **)&list->str);
		ft_memdel((void **)&list);
		list = *begin;
	}
	*begin = NULL;
}

void				ft_supp_lststr(t_lststr **begin)
{
	t_lststr	*list;
	t_lststr	*temp;

	if (*begin == NULL)
		return ;
	list = *begin;
	if (list->next == NULL)
	{
		ft_lststr_del(begin);
		return ;
	}
	while (list->next)
	{
		temp = list;
		list = list->next;
	}
	ft_lststr_del(&temp->next);
}
