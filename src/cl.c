/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 18:53:25 by rtacos            #+#    #+#             */
/*   Updated: 2020/09/12 16:59:27 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	run_cl(t_fr *frac)
{
	char	*src;
	size_t	file_size;
	cl_int	ret;

	file_size = read_cl_file(&src, selection_of_fractol(frac->num_fract));
	frac->cl.program = clCreateProgramWithSource(frac->cl.context, 1,
					(const char **)&src, (const size_t *)&file_size, &ret);
	if (ret != 0)
		cl_error("Error with CreateProgramWithSource\n");
	if ((ret = clBuildProgram(frac->cl.program, 1, &frac->cl.did,
											"-I includes/", NULL, NULL)))
		print_error_log(frac->cl);
	frac->cl.kernel = clCreateKernel(frac->cl.program, "check_iter", &ret);
	if (ret != 0)
		cl_error("Error with CreateKernel\n");
	draw(*frac);
	free(src);
}

void	creat_img_buf(t_cl *cl, int *img_data)
{
	cl_int	ret;

	cl->img = clCreateBuffer(cl->context, CL_MWO,\
			WIN_HIG * WIN_WID * sizeof(cl_int), NULL, &ret);
	if (ret)
		cl_error("Error with CreateBuffer[img]\n");
	if ((ret = clEnqueueWriteBuffer(cl->com_queue, cl->img, CL_TRUE, 0,
			WIN_HIG * WIN_WID * sizeof(cl_int), img_data, 0, NULL, NULL)))
		cl_error("Error with EnqueueWriteBuffer[img]\n");
}

void	init_cl(t_cl *cl, int *img_data)
{
	cl_int	ret;

	if ((ret = clGetPlatformIDs(2, &cl->pid, &cl->ret_num_platf)))
		cl_error("Error with GetPlatformIDs\n");
	if ((ret = clGetDeviceIDs(cl->pid, CL_DTG, 1, &cl->did, &cl->n_devs)))
		cl_error("Error with GetDeviceIDs\n");
	cl->context = clCreateContext(NULL, 1, &cl->did, NULL, NULL, &ret);
	if (ret)
		cl_error("Error with CreateContext\n");
	cl->com_queue = clCreateCommandQueue(cl->context, cl->did, 0, &ret);
	if (ret)
		cl_error("Error with CreateCommandQueue\n");
	creat_img_buf(cl, img_data);
}
