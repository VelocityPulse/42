/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <cchameyr@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:50:45 by cchameyr          #+#    #+#             */
/*   Updated: 2015/11/28 15:38:09 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s) - 1;
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
		len--;
	len++;
	while ((i < len) && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	len = len - i;
	str = ft_strnew(len);
	str = ft_strsub((char *)s, i, len);
	return (str);
}
