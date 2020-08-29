/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 17:16:06 by rtacos            #+#    #+#             */
/*   Updated: 2020/08/29 18:53:57 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
#define FT_FRACTOL_H

# include <OpenCL/cl.h>
# include <stdlib.h>
# include <math.h>
# include "../src/libft/libft.h"
# include <unistd.h>
# include <mlx.h>

# define WIN_WID 2400
# define WIN_HIG 1350
# define CL_DTD CL_DEVICE_TYPE_DEFAULT

struct			s_fr
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		*img_data;
	void	*img_ptr;
	void	(*check_pix_iter)(double, double);
	int		color;
	double	x_st;
	double	y_st;
}				g_fr;

struct			s_cl
{
	cl_int				ret;
	cl_platform_id		pid;
	cl_uint				ret_num_platf;
	cl_device_id		did;
	cl_uint				n_devs;
	cl_context			context;
	cl_command_queue	com_queue;
}				g_cl;


struct	s_color
{
	double r;
	double g;
	double b;
	int al;
}		g_color;

int		fractal;
double	g_zoom;
int		g_iter_max;

void		print_mandelbr(int **img_data);
void		init_img(void);
int			key_press(int key);
void		check_iter_mandelbr(double x_st, double y_st);
void		print_fract(int **img_data, void (*check_pix_iter)(double, double));

void		init_cl();
void		cl_error();

#endif