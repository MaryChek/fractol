/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 18:53:25 by rtacos            #+#    #+#             */
/*   Updated: 2020/08/29 18:53:30 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	cl_error()
{
	ft_putstr_fd("error with OpenCL", 1);
	exit;
}

void	init_cl()
{
	if (g_cl.ret = clGetPlatformIDs(1, &g_cl.pid, &g_cl.ret_num_platf))
		cl_error(g_cl.ret);
	if (g_cl.ret = clGetDeviceIDs(g_cl.pid, CL_DTD, 1, &g_cl.did, &g_cl.n_devs))
		cl_error(g_cl.ret);
	g_cl.context = clCreateContext(NULL, 1, &g_cl.did, NULL, NULL, &g_cl.ret);
	g_cl.com_queue = clCreateCommandQueue(g_cl.context, g_cl.did, 0, &g_cl.ret);
}