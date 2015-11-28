/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <cchameyr@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 12:22:34 by cchameyr          #+#    #+#             */
/*   Updated: 2015/11/28 14:11:04 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_strsplit_len(char const *s, char c)
{
	int t_len;
	int i;

	i = 0;
	t_len = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			t_len++;
		while (s[i] != c && s[i])
			i++;
	}
	return (t_len);
}

int		ft_strsplit_word_len(char const *s, char c)
{
	int i;

	i = 0;
	while (s[i])
	{
		while (s[i] != c && s[i])
			i++;
	}
	return (i);
}

char	**ft_strsplit(char const *s, char c)
{
	int		index;
	int		i;
	int		t_len;
	char	**t_str;

	i = 0;
	if (s[i] && c)
	{
		t_len = ft_strsplit_len(s, c);
		t_str = (char **)malloc(sizeof(char) * t_len + 1);
		ft_bzero(t_str, t_len + 1);
		while (index <= t_len && s[i])
		{
			index++;
			while (s[i] == c && s[i])
				i++;
			if (s[i] != c && s[i])
				t_str[index] = ft_strsub(s, i, ft_strsplit_word_len(&s[i], c));
			while (s[i] != c && s[i])
				i++;
		}
		return (t_str);
	}
	return (NULL);
}

