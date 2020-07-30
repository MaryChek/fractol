/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 17:16:06 by rtacos            #+#    #+#             */
/*   Updated: 2020/07/30 20:20:44 by rtacos           ###   ########.fr       */
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
# define ZOOM 20
# define ITER_MAX 200

typedef struct	s_fr
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_fr;

extern struct	s_color
{
	int r;
	int g;
	int b;
	int al;
}				g_color;

void		print_mandelbr(void);
void		init_img(void);

#endif