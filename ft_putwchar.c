/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 14:22:14 by cchameyr          #+#    #+#             */
/*   Updated: 2016/09/05 14:22:20 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static int		ft_write_mask(char *mask, int bytes)
{
	int		i;
	int		w;

	i = -1;
	while (++i < bytes)
	{
		w = ft_atoi_nbase(&mask[i * 8], 2, 8);
		write(1, &w, 1);
	}
	return (bytes);
}

static int		ft_wchar_help(int c, char *mask, int bytes)
{
	int		i;

	i = (8 * bytes) - 1;
	while (i && c)
	{
		if (mask[i] != 'x')
			i--;
		else
		{
			mask[i--] = 48 + (c % 2);
			c = c / 2;
		}
	}
	i = -1;
	while (mask[++i])
	{
		if (mask[i] == 'x')
			mask[i] = '0';
	}
	return (ft_write_mask(mask, bytes));
}

int				ft_putwchar(int c)
{
	int		len;
	char	mask2[16];
	char	mask3[24];
	char	mask4[32];

	len = ft_binlen(c);
	if (len <= 7)
		return (write(1, &c, 1));
	else if (len <= 11)
	{
		ft_strcpy(mask2, "110xxxxx10xxxxxx");
		return (ft_wchar_help(c, mask2, 2));
	}
	else if (len > 11 && len <= 16)
	{
		ft_strcpy(mask3, "1110xxxx10xxxxxx10xxxxxx");
		return (ft_wchar_help(c, mask3, 3));
	}
	else if (len > 16 && len <= 21)
	{
		ft_strcpy(mask4, "11110xxx10xxxxxx10xxxxxx10xxxxxx");
		return (ft_wchar_help(c, mask4, 4));
	}
	else
		return (0);
}
