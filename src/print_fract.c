/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 17:16:02 by rtacos            #+#    #+#             */
/*   Updated: 2020/07/31 18:58:43 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	check_pix_iter(double x_st, double y_st)
{
	int iter;
	double x_n;
	double x;
	double y;
	double col;
	int color;

	x = 0;
	y = 0;
	
	iter = -1;
	color = 0x7403dd;
	while ((x * x + y * y) <= 200.00 && ++iter < ITER_MAX)
	{
		x_n = x;
		x = x_n * x_n - y * y + x_st;
		y = 2 * x_n * y + y_st;
	}
	col = (double)iter - log2(log2((x * x) + (y * y))) + 5.0;
	if (iter == ITER_MAX)
	{
		g_color.r = 0;
		g_color.g = 0;
		g_color.b = 0;
	}
	else
	{
		g_color.r = 0.5 + 0.5 * cos(0.5 * col + (9.5 * color));
		g_color.g = 0.5 + 0.5 * cos(0.5 * col + (19.5 * color));
		g_color.b = 0.5 + 0.5 * cos(0.5 * col + (18.8 * (color)));
	}
}

void		print_mandelbr(int **img_data)
{
	double x, y, x_st, y_st;
	int *tmp;

	x_st = - (WIN_WID / 2);
	y_st = - (WIN_HIG / 2);
	y = y_st;
	tmp = *img_data;
	while (y < (WIN_HIG / 2))
	{
		x = x_st;
		while (x < (WIN_WID / 2))
		{
			if (y == 0 && x == 0)
			{
				y = 0;
			}
			check_pix_iter(x * ZOOM, y * ZOOM);
			tmp[(int)((x - x_st) + (y - y_st) * WIN_WID)] = (int)(g_color.r * 255) << 16 | (int)(g_color.g * 255) << 8 | (int)(g_color.b * 255);
			x++;
		}
		y++;
	}
	
}

void	init_img(t_fr *fr, int **img_data, void **img_ptr)
{
	int		bpp;
	int		size_line;
	int		endian;
	
	fr->mlx_ptr = mlx_init();
	fr->win_ptr = mlx_new_window(fr->mlx_ptr, WIN_WID, WIN_HIG, "fdf");
	*img_ptr = mlx_new_image(fr->mlx_ptr, WIN_WID, WIN_HIG);
	*img_data = (int *)mlx_get_data_addr(*img_ptr, &bpp, &size_line, &endian);
	
	
}