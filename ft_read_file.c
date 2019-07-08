/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <cchameyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 14:50:14 by cchameyr          #+#    #+#             */
/*   Updated: 2019/07/08 17:07:34 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>

t_bin		*ft_read_file(char *path)
{
	int			fd;
	void		*ptr;
	struct stat buff;
	t_bin		*data;

	if ((fd = open(path, O_RDONLY)) < 0)
		return NULL;
	if (fstat(fd, &buff) < 0)
		return NULL;
	if ((ptr = mmap(0, buff.st_size, PROT_READ, MAP_PRIVATE, fd, 0)) ==
				MAP_FAILED)
		return NULL;
	data = (t_bin *)ft_memalloc(sizeof(t_bin));
	data->data = ptr;
	data->size = buff.st_size;
	return data;
}
