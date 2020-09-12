/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 19:58:06 by rtacos            #+#    #+#             */
/*   Updated: 2020/09/11 22:01:21 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	send_arg_to_kernel_next(t_fr frac)
{
	cl_int	ret;
	double	jul_par;

	if ((ret = clSetKernelArg(frac.cl.kernel, 7, sizeof(cl_int),
													(void *)&frac.cl.x_shift)))
		cl_error("Error with SetKernelArg[x_sh]\n");
	if ((ret = clSetKernelArg(frac.cl.kernel, 8, sizeof(t_coord),
													(void *)&frac.mv_mouse)))
		cl_error("Error with SetKernelArg[mv_mouse]\n");
	if (frac.num_fract == JULIA || frac.num_fract == JULIA_BR_SH
				|| frac.num_fract == JUL_FISH)
	{
		if ((ret = clSetKernelArg(frac.cl.kernel, 9, sizeof(t_coord),
														(void *)&frac.mouse)))
			cl_error("Error with SetKernelArg[mouse]\n");
		jul_par = (double)(WIN_HIG > WIN_WID ? 2.5 / WIN_WID : 2.5 / WIN_HIG);
		if ((ret = clSetKernelArg(frac.cl.kernel, 10, sizeof(double),
														(void *)&jul_par)))
			cl_error("Error with SetKernelArg[jul_par]\n");
	}
}

void	send_arg_to_kernel(int wid, int hig, t_fr frac)
{
	cl_int	ret;

	if ((ret = clSetKernelArg(frac.cl.kernel, 0, sizeof(cl_mem),
														(void *)&frac.cl.img)))
		cl_error("Error with SetKernelArg[img]\n");
	if ((ret = clSetKernelArg(frac.cl.kernel, 1, sizeof(int),
														(void *)&frac.color)))
		cl_error("Error with SetKernelArg[g_color]\n");
	if ((ret = clSetKernelArg(frac.cl.kernel, 2, sizeof(int), (void *)&wid)))
		cl_error("Error with SetKernelArg[wid]\n");
	if ((ret = clSetKernelArg(frac.cl.kernel, 3, sizeof(int), (void *)&hig)))
		cl_error("Error with SetKernelArg[wid]\n");
	if ((ret = clSetKernelArg(frac.cl.kernel, 4, sizeof(double),
													(void *)&frac.iter_max)))
		cl_error("Error with SetKernelArg[iter_max]\n");
	if ((ret = clSetKernelArg(frac.cl.kernel, 5, sizeof(double),
														(void *)&frac.zoom)))
		cl_error("Error with SetKernelArg[zoom]\n");
	if ((ret = clSetKernelArg(frac.cl.kernel, 6, sizeof(cl_int),
													(void *)&frac.cl.y_shift)))
		cl_error("Error with SetKernelArg[y_sh]\n");
	send_arg_to_kernel_next(frac);
}

void	send_arg_to_kernel1(t_fr frac)
{
	int wid;
	int hig;

	wid = WIN_WID;
	hig = WIN_HIG;
	send_arg_to_kernel(wid, hig, frac);
}

void	draw(t_fr frac)
{
	size_t	g_w_size;
	cl_int	ret;

	g_w_size = WIN_WID * WIN_HIG;
	send_arg_to_kernel1(frac);
	if ((ret = clEnqueueNDRangeKernel(frac.cl.com_queue, frac.cl.kernel,
						1, NULL, &g_w_size, NULL, 0, NULL, NULL)))
		cl_error("Error with EnqueueNDRangeKernel\n");
	if ((ret = clEnqueueReadBuffer(frac.cl.com_queue, frac.cl.img, CL_TRUE,
		0, WIN_HIG * WIN_WID * sizeof(int), frac.img_data, 0, NULL, NULL)))
		cl_error("Error with EnqueueReadBuffer[img]\n");
	mlx_put_image_to_window(frac.mlx_ptr, frac.win_ptr, frac.img_ptr, 0, 0);
	put_str_help(frac.mlx_ptr, frac.win_ptr,
										frac.help, frac.clr_txt);
}
