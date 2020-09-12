/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_cl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 15:18:08 by rtacos            #+#    #+#             */
/*   Updated: 2020/09/12 17:07:55 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	clear_cl(t_cl cl, int key)
{
	int ret;

	if ((ret = clReleaseKernel(cl.kernel)))
		cl_error("Error whith Release Kernel\n");
	if ((ret = clReleaseProgram(cl.program)))
		cl_error("Error whith Release Program\n");
	if (key == 1)
	{
		if ((ret = clFinish(cl.com_queue)))
			cl_error("Error whith Finish\n");
		if ((ret = clFlush(cl.com_queue)))
			cl_error("Error whith Flush\n");
		if ((ret = clReleaseMemObject(cl.img)))
			cl_error("Error whith img_obj\n");
		if ((ret = clReleaseCommandQueue(cl.com_queue)))
			cl_error("Error whith Release ComQueue\n");
		if ((ret = clReleaseContext(cl.context)))
			cl_error("Error whith Release Context\n");
		if ((ret = clReleaseDevice(cl.did)))
			cl_error("Error whith Release Device\n");
		exit(0);
	}
}
