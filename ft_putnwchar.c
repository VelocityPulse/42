/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnwchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 22:39:54 by                   #+#    #+#             */
/*   Updated: 2016/08/27 00:29:11 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static int		ft_write_mask(char *mask, int bytes, int len)
{
	int		i;
	int		w;

	i = -1;
	while (++i < bytes && len--)
	{
		w = ft_atoi_nbase(&mask[i * 8], 2, 8);
		write(1, &w, 1);
	}
	return (bytes);
}

static int		ft_wchar_help(int c, char *mask, int bytes, int len)
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
	return (ft_write_mask(mask, bytes, len));
}

int				ft_putnwchar(int c, int len)
{
	int		len2;
	char	mask2[16];
	char	mask3[24];
	char	mask4[32];

	if (len < 0)
		return (0);
	len2 = ft_binlen(c);
	if (len2 <= 7 && len > 0)
		return (write(1, &c, 1));
	else if (len2 <= 11)
	{
		ft_strcpy(mask2, "110xxxxx10xxxxxx");
		return (ft_wchar_help(c, mask2, 2, len));
	}
	else if (len2 > 11 && len2 <= 16)
	{
		ft_strcpy(mask3, "1110xxxx10xxxxxx10xxxxxx");
		return (ft_wchar_help(c, mask3, 3, len));
	}
	else
	{
		ft_strcpy(mask4, "11110xxx10xxxxxx10xxxxxx10xxxxxx");
		return (ft_wchar_help(c, mask4, 4, len));
	}
}
