/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <cchameyr@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:36:23 by cchameyr          #+#    #+#             */
/*   Updated: 2015/11/25 23:21:23 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		size;
	int		cpt;
	char	*s2;

	cpt = 0;
	size = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(char) * (size + 1));
	while (s1[cpt])
	{
		s2[cpt] = s1[cpt];
		cpt++;
	}
	return (s2);
}
