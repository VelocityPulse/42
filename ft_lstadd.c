/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <cchameyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 12:36:15 by cchameyr          #+#    #+#             */
/*   Updated: 2019/08/01 13:03:16 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstadd(t_list **alst, t_list *new)
{
	t_list	*item;

	if (alst == NULL)
		return (NULL);
	if (*alst == NULL)
	{
		*alst = new;
		return (new);
	}
	item = *alst;
	while (item->next != NULL)
		item = item->next;
	item->next = new;
	return (new);
}
