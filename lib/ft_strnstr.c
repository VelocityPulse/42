/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <cchameyr@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:05:15 by cchameyr          #+#    #+#             */
/*   Updated: 2015/11/26 00:45:16 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int		cpt;
	int		cpt2;
	int		size;

	cpt = 0;
	cpt2 = 0;
	size = ft_strlen(s2);
	if (!size)
		return ((char *)s1);
	while (s1[cpt])
	{
		while (s2[cpt2] == s1[cpt + cpt2] && cpt + cpt2 < n)
		{
			if (cpt2 == size - 1)
				return ((char *)&s1[cpt]);
			cpt2++;
		}
		cpt2 = 0;
		cpt++;
	}
	return (NULL);
}
