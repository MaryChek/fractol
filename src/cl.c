/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 18:53:25 by rtacos            #+#    #+#             */
/*   Updated: 2020/09/08 20:06:07 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

size_t	read_cl_file(char **src, const char *file_name) /// двумерный массив
{
	int		fd;
	char	*tmp;
	size_t	size_r;
	size_t	r;
	char	buf[11];

	if ((fd = open(file_name, O_RDONLY)) < 0)
		cl_error("Can't open file\n");
	*src = ft_strnew(0);
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

void	init_cl()
{
	cl_int	ret;

	if ((ret = clGetPlatformIDs(1, &g_cl.pid, &g_cl.ret_num_platf)))
		cl_error("Error with GetPlatformIDs\n");
	if ((ret = clGetDeviceIDs(g_cl.pid, CL_DTD, 1, &g_cl.did, &g_cl.n_devs)))
		cl_error("Error with GetDeviceIDs\n");
	g_cl.context = clCreateContext(NULL, 1, &g_cl.did, NULL, NULL, &ret);
	if (ret)
		cl_error("Error with CreateContext\n");
	g_cl.com_queue = clCreateCommandQueue(g_cl.context, g_cl.did, 0, &ret);
	if (ret)
		cl_error("Error with CreateCommandQueue\n");
	g_cl.img = clCreateBuffer(g_cl.context, CL_MWO,
				sizeof(cl_int) * WIN_HIG * WIN_WID, NULL, &ret);
	if (ret)
		cl_error("Error with CreateBuffer[img]\n");
}

char	*selection_of_fractol()
{
	if (g_fr.num_fract == MANDELBROT)
		return (MANDELBROT_SRC);
	if (g_fr.num_fract == JULIA)
		return (JULIA_SRC);
	return (NULL);
}

int		Set_Kernel_Arg(int num, size_t size, void *param)
{
	return (clSetKernelArg(g_cl.kernel, num, size, param));
}

void	set_arg_for_julia()
{
	cl_int		ret;
	cl_double	jul_par;

	if (g_fr.num_fract == JULIA)
	{
		if ((ret = Set_Kernel_Arg(9, sizeof(t_coord), (void *)&g_fr.mouse)))
			cl_error("Error with SetKernelArg[mouse]\n");
		jul_par = (double)(WIN_HIG > WIN_WID ? 2.5 / WIN_WID : 2.5 / WIN_HIG);
		if ((ret = Set_Kernel_Arg(10, sizeof(cl_double), (void *)&jul_par)))
			cl_error("Error with SetKernelArg[jul_par]\n");
	}
}

void	send_arg_to_kernel(int wid, int hig)
{
	cl_int	ret;

	if ((ret = clEnqueueWriteBuffer(g_cl.com_queue, g_cl.img, CL_TRUE, 0,
				WIN_HIG * WIN_WID * sizeof(cl_int), g_fr.img_data,
														 0, NULL, NULL)))
		cl_error("Error with EnqueueWriteBuffer[img]\n");
	if ((ret = Set_Kernel_Arg(0, sizeof(cl_mem), (void *)&g_cl.img)))
		cl_error("Error with SetKernelArg[img]\n");
	if ((ret = Set_Kernel_Arg(1, sizeof(cl_int), (void *)&g_fr.color)))
		cl_error("Error with SetKernelArg[g_color]\n");
	if ((ret = Set_Kernel_Arg(2, sizeof(cl_int), (void *)&wid)))
		cl_error("Error with SetKernelArg[wid]\n");
	if ((ret = Set_Kernel_Arg(3, sizeof(cl_int), (void *)&hig)))
		cl_error("Error with SetKernelArg[wid]\n");
	if ((ret = Set_Kernel_Arg(4, sizeof(cl_int), (void *)&g_fr.iter_max)))
		cl_error("Error with SetKernelArg[iter_max]\n");
	if ((ret = Set_Kernel_Arg(5, sizeof(cl_double), (void *)&g_fr.zoom)))
		cl_error("Error with SetKernelArg[zoom]\n");
	if ((ret = Set_Kernel_Arg(6, sizeof(cl_int), (void *)&g_cl.y_shift)))
		cl_error("Error with SetKernelArg[y_sh]\n");
	if ((ret = Set_Kernel_Arg(7, sizeof(cl_int), (void *)&g_cl.x_shift)))
		cl_error("Error with SetKernelArg[x_sh]\n");
	if ((ret = Set_Kernel_Arg(8, sizeof(t_coord), (void *)&g_fr.mv_mouse)))
		cl_error("Error with SetKernelArg[mv_mouse]\n");
	set_arg_for_julia();
}

void	send_arg_to_kernel1()
{
	int wid;
	int hig;

	wid = WIN_WID;
	hig = WIN_HIG;
	send_arg_to_kernel(wid, hig);
}

void	print_error_log()
{
	size_t log_size;
	char *log;

	clGetProgramBuildInfo(g_cl.program, g_cl.did, CL_PROGRAM_BUILD_LOG, 0, NULL, &log_size);
	log = (char *)malloc(log_size);
	clGetProgramBuildInfo(g_cl.program, g_cl.did, CL_PROGRAM_BUILD_LOG, log_size, log, NULL);
	ft_putstr(log);
	free(log);
}

// int				get_color(t_color rgb)
// {
// 	int clr;

// 	clr = (int)(rgb.r * 255) << 16;
// 	clr += (int)(rgb.g * 255) << 8;
// 	clr += (int)(rgb.b * 255);
// 	return (clr);
// }

// void	print_img()
// {
// 	int i;

// 	i = -1;
// 	while (++i < (WIN_HIG * WIN_WID))
// 	{
// 	int			iter;
// 	double		x_n;
// 	double		x;
// 	double		y;
// 	double		col;
// 	double		y_st;
// 	double		x_st;
// 	t_color		rgb;

// 	x = 0;
// 	y = 0;
// 	x_st = (double)(((i % WIN_WID) + g_cl.x_shift) * g_fr.zoom + g_fr.mv_mouse.x);
// 	y_st = (double)(((i / WIN_WID) + g_cl.y_shift) * g_fr.zoom + g_fr.mv_mouse.y);
// 	iter = -1;
// 	if (((i % WIN_WID) - WIN_WID/2) == g_fr.mouse.x && ((i / WIN_WID) - WIN_HIG/2) == g_fr.mouse.y)
// 	{
// 		int a = 2;
// 		a++;
// 	}
// 	while ((x * x + y * y) <= 200.00 && ++iter < g_fr.iter_max)
// 	{
// 		x_n = x;
// 		x = x_n * x_n - y * y + x_st;
// 		y = 2 * x_n * y + y_st;
// 	}
// 	col = (double)(iter - log2(log2((x * x) + (y * y))) + 5.0);
// 	if (iter != g_fr.iter_max)
// 	{
// 		rgb.r = 0.5 + 0.5 * cos(0.5 * col + (9.5 * g_fr.color));
// 		rgb.g = 0.5 + 0.5 * cos(0.5 * col + (19.5 * g_fr.color));
// 		rgb.b = 0.5 + 0.5 * cos(0.5 * col + (18.8 * g_fr.color));
// 		g_fr.img_data[i] = get_color(rgb);
// 	}
// 	else
// 		g_fr.img_data[i] = 0;
// 	}
// }

void	run_cl()
{
	char	*src;
	size_t	file_size;
	cl_int	ret;
	size_t	g_w_size;

	g_w_size = WIN_WID * WIN_HIG;
	file_size = read_cl_file(&src, selection_of_fractol());
	g_cl.program = clCreateProgramWithSource(g_cl.context, 1,
					(const char **)&src, (const size_t *)&file_size, &ret);
	if (ret != 0)
		cl_error("Error with CreateProgramWithSource\n");
	if ((ret = clBuildProgram(g_cl.program, 1, &g_cl.did,
											"-I includes/", NULL, NULL)))
		print_error_log();
	g_cl.kernel = clCreateKernel(g_cl.program, "check_iter", &ret);
	if (ret != 0)
		cl_error("Error with CreateKernel\n");
	send_arg_to_kernel1();
	if ((ret = clEnqueueNDRangeKernel(g_cl.com_queue, g_cl.kernel, 1, NULL,
									&g_w_size, NULL, 0, NULL, NULL)))
		cl_error("Error with EnqueueNDRangeKernel\n");
	if ((ret = clEnqueueReadBuffer(g_cl.com_queue, g_cl.img, CL_TRUE, 0,
			WIN_HIG * WIN_WID * sizeof(int), g_fr.img_data, 0, NULL, NULL)))
		cl_error("Error with EnqueueReadBuffer[img]\n");
	free(src);
	// print_img();
}
