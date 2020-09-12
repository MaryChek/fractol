/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 17:16:06 by rtacos            #+#    #+#             */
/*   Updated: 2020/09/12 17:36:12 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include <OpenCL/cl.h>
# include <stdlib.h>
# include <math.h>
# include "libft.h"
# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>

# define WIN_WID 1920
# define WIN_HIG 1080
# define CL_DTG CL_DEVICE_TYPE_GPU
# define CL_MWO CL_MEM_WRITE_ONLY
# define CL_MRO CL_MEM_READ_ONLY
# define CL_MRW CL_MEM_READ_WRITE
# define CL_PBL CL_PROGRAM_BUILD_LOG

# define MANDELBROT_SRC "src/cl/mandelbrot.cl"
# define JULIA_SRC "src/cl/julia.cl"
# define BURN_SHIP_SRC "src/cl/burn_ship.cl"
# define JULIA_BR_SH_SRC "src/cl/julia_burn_ship.cl"
# define FISH_SRC "src/cl/fish.cl"
# define JUL_FISH_SRC "src/cl/julia_fish.cl"

enum			e_fractal
{
	MANDELBROT,
	JULIA,
	BURN_SHIP,
	JULIA_BR_SH,
	FISH,
	JUL_FISH,
};

typedef struct	s_color
{
	double	r;
	double	g;
	double	b;
}				t_color;

typedef	struct	s_coord
{
	double	x;
	double	y;
}				t_coord;

typedef struct	s_cl
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
	cl_int				y_shift;
	cl_int				x_shift;
}				t_cl;

typedef struct	s_fr
{
	void				*mlx_ptr;
	void				*win_ptr;
	int					*img_data;
	void				*img_ptr;
	int					num_fract;
	int					color;
	double				zoom;
	double				iter_max;
	t_coord				mouse;
	t_coord				mv_mouse;
	double				speed_zm;
	int					button_jul;
	int					iter_up_auto;
	int					help;
	int					clr_txt;
	t_cl				cl;
}				t_fr;

typedef int		(*t_pft)(t_fr *frac);

typedef struct	s_data
{
	t_pft				init_fr[6];
	t_fr				frac;
}				t_data;

int				init_mandelbrot(t_fr *frac);
int				init_julia(t_fr *frac);
int				init_burn_ship(t_fr *frac);
int				init_jul_burn_ship(t_fr *frac);
int				init_fish(t_fr *frac);
int				init_jul_fish(t_fr *frac);

void			init_img(t_fr *frac);
void			init_cl(t_cl *cl, int *img_data);

char			*selection_of_fractol(int num_fract);
void			send_arg_to_kernel_next(t_fr frac);

void			run_cl(t_fr *frac);
void			draw(t_fr frac);
size_t			read_cl_file(char **src, const char *file_name);

void			cl_error(char *error_mess);
void			write_usage(void);
void			print_error_log(t_cl cl);
int				clos_e(int num);

int				key_press(int key, t_data *data);
int				mouse_press(int button, int x, int y, t_fr *frac);
int				mouse_move(int x, int y, t_fr *frac);

void			put_str_help(void *mlx_ptr, void *win_ptr, int help, int col);
void			clear_cl(t_cl cl, int key);

#endif
