/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 17:16:06 by rtacos            #+#    #+#             */
/*   Updated: 2020/07/31 18:30:20 by rtacos           ###   ########.fr       */
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
# define MANDELBROT 1
# define ZOOM 0.002
# define ITER_MAX 200

typedef struct	s_fr
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_fr;

struct	s_color
{
	double r;
	double g;
	double b;
	int al;
}		g_color;

void		print_mandelbr(int **img_data);
void		init_img(t_fr *fr, int **img_data, void **img_ptr);

#endif