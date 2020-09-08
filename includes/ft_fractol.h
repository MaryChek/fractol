/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 17:16:06 by rtacos            #+#    #+#             */
/*   Updated: 2020/09/08 19:36:53 by rtacos           ###   ########.fr       */
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
# include <fcntl.h>
# include <stdio.h>

# define WIN_WID 1920
# define WIN_HIG 1080
# define CL_DTD CL_DEVICE_TYPE_DEFAULT
# define CL_MWO CL_MEM_WRITE_ONLY
# define CL_MRO CL_MEM_READ_ONLY
# define CL_MRW CL_MEM_READ_WRITE

# define MANDELBROT_SRC "src/mandelbrot.cl"
# define JULIA_SRC "src/julia.cl"

enum fractal
{
	MANDELBROT,
	JULIA,
};

typedef struct		s_min_max
{
	int		min;
	int		max;
}					t_min_max;

typedef	struct	s_coord
{
	double	x;
	double	y;
}				t_coord;

struct			s_fr
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		*img_data;
	void	*img_ptr;
	int		num_fract;
	int		color;
	int		fractal;
	double	zoom;
	int		iter_max;
	t_coord	mouse;
	t_coord	mv_mouse;
	double	speed_zm;
	int		button_jul;
}				g_fr;

struct			s_cl
{
	cl_platform_id		pid;
	cl_uint				ret_num_platf;
	cl_device_id		did;
	cl_uint				n_devs;
	cl_context			context;
	cl_command_queue	com_queue;
	cl_mem				img;
	cl_program			program;
	cl_kernel			kernel;
	size_t				g_w_size;
	cl_int				y_shift;
	cl_int				x_shift;
}				g_cl;

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
}				t_color;


// int		g_color;
// int		fractal;
// double	g_zoom;
// int		g_iter_max;

void		init_img(void);
int			key_press(int key);
void		run_cl();
void		init_cl();
void		cl_error(char *error_mess);
size_t		read_cl_file(char **src, const char *file_name);

void	print_fract(int **img_data);
int		mouse_press(int button, int x, int y);
int		SetKernelArg(int num, size_t size, void *param);
int		mouse_move(int x, int y);

#endif