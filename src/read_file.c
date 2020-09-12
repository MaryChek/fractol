/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 03:53:40 by rtacos            #+#    #+#             */
/*   Updated: 2020/09/12 17:13:45 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

size_t	read_cl_file(char **src, const char *file_name)
{
	int		fd;
	char	*tmp;
	size_t	size_r;
	size_t	r;
	char	buf[11];

	if ((fd = open(file_name, O_RDONLY)) < 0)
		cl_error("Can't open file\n");
	if (!(*src = ft_strnew(0)))
		cl_error("Error with malloc [src]\n");
	size_r = 0;
	while ((r = read(fd, buf, 10)))
	{
		buf[r] = '\0';
		tmp = *src;
		if ((*src = ft_strjoin(*src, buf)) == NULL)
			cl_error("error with ft_strjoin\n");
		ft_strdel(&tmp);
		size_r += r;
	}
	close(fd);
	return (size_r);
}
