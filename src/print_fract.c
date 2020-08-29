/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 17:16:02 by rtacos            #+#    #+#             */
/*   Updated: 2020/08/04 20:18:49 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	check_iter_mandelbr(double x_st, double y_st)
{
	int iter;
	double x_n;
	double x;
	double y;
	double col;

	x = 0;
	y = 0;
	iter = -1;
	while ((x * x + y * y) <= 200.00 && ++iter < g_iter_max)
	{
		x_n = x;
		x = x_n * x_n - y * y + x_st;
		y = 2 * x_n * y + y_st;
	}
	col = (double)iter - log2(log2((x * x) + (y * y))) + 5.0;
	if (iter != g_iter_max)
	{
		g_color.r = 0.5 + 0.5 * cos(0.5 * col + (9.5 * g_fr.color));
		g_color.g = 0.5 + 0.5 * cos(0.5 * col + (19.5 * g_fr.color));
		g_color.b = 0.5 + 0.5 * cos(0.5 * col + (18.8 * (g_fr.color)));
	}
}

void	put_color_in_pix(int **tmp, int x, int y)
{
	int color;

	color = (int)(g_color.r * 255) << 16;
	color += (int)(g_color.g * 255) << 8;
	color += (int)(g_color.b * 255);
	(*tmp)[(int)((x - g_fr.x_st) + (y - g_fr.y_st) * WIN_WID)] = color;
	g_color.r = 0;
	g_color.g = 0;
	g_color.b = 0;
}

void	print_fract(int **img_data, void (*check_pix_iter)(double, double))
{
	double	x;
	double	y;
	int		*tmp;

	y = g_fr.y_st;
	tmp = *img_data;
	while (y < (g_fr.y_st + WIN_HIG))
	{
		x = g_fr.x_st;
		while (x < (g_fr.x_st + WIN_WID))
		{
			check_pix_iter(x * g_zoom, y * g_zoom);
			put_color_in_pix(&tmp, x, y);
			x++;
		}
		y++;
	}
}

void	init_img(void)
{
	int		bpp;
	int		size_line;
	int		endian;

	g_color.r = 0;
	g_color.g = 0;
	g_color.b = 0;
	g_fr.color = 0x7403dd;
	g_zoom = 0.002;
	g_iter_max = 200;
	g_fr.x_st = - (WIN_WID / 2);
	g_fr.y_st = - (WIN_HIG / 2);
	g_fr.mlx_ptr = mlx_init();
	g_fr.win_ptr = mlx_new_window(g_fr.mlx_ptr, WIN_WID, WIN_HIG, "fdf");
	g_fr.img_ptr = mlx_new_image(g_fr.mlx_ptr, WIN_WID, WIN_HIG);
	g_fr.img_data = (int *)mlx_get_data_addr(g_fr.img_ptr, &bpp, &size_line, &endian);
}