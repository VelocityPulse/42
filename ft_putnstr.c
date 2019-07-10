/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <cchameyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 14:29:33 by cchameyr          #+#    #+#             */
/*   Updated: 2019/07/10 21:05:01 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int		ft_putnstr(char const *s, size_t len)
{
	size_t	i;

	i = -1;
	while (++i < len)
		write(1, &s[i], 1);
	return (i);
}
