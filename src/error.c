/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 03:48:38 by rtacos            #+#    #+#             */
/*   Updated: 2020/09/12 18:59:09 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	cl_error(char *error_mess)
{
	ft_putstr_fd(error_mess, 1);
	exit(0);
}

void	write_usage(void)
{
	write(1, "usage: ./fractol name_fractal\n\n", 31);
	write(1, "Name_fractal:\n\t- Mandelbrot\n\t- Julia\n\t", 38);
	write(1, "- Burn_ship\n\t- Jul_Burn_ship\n\t- Fish\n\t- Jul_fish\n", 49);
}

void	print_error_log(t_cl cl)
{
	size_t	log_size;
	char	*log;

	clGetProgramBuildInfo(cl.program, cl.did, CL_PBL, 0, NULL, &log_size);
	if (!(log = (char *)malloc(log_size)))
		cl_error("malloc error [log]\n");
	clGetProgramBuildInfo(cl.program, cl.did, CL_PBL, log_size, log, NULL);
	ft_putstr(log);
	free(log);
}

int		clos_e(int num)
{
	exit(num);
	return (0);
}
