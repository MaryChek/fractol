/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 17:16:02 by rtacos            #+#    #+#             */
/*   Updated: 2020/07/30 20:24:40 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"


void	put_color_in_img(int **img_data)
{
	int x, y;
	int *tmp;

	x = -1;
	y = -1;
	tmp = *img_data;
	while (++y < WIN_HIG)
	{
		while (++x < WIN_WID)
		{
			*tmp++ = 255 << 16 | 205 << 8 | 255;
		}
		x = -1;
	}
}

void	check_pix_iter(int x, int y, int x_st, int y_st)
{
	int iter;
	int x_n;
	
	iter = 0;
	while ((x * x + y * y) > 4 && iter++ <= ITER_MAX)
	{
		x_n = x;
		x = x_n * x_n - y * y + x_st;
		y = 2 * x_n * y + y_st;
	}
	
}

void		print_mandelbr(void)
{
	int x, y, x_st, y_st, x_n;

	x_st = - (WIN_WID / 2) * ZOOM;
	y_st = - (WIN_HIG / 2) * ZOOM;
	y = y_st;
	while (y < WIN_HIG)
	{
		x = x_st;
		while (x < WIN_WID)
		{
			check_pix_iter(x, y, x_st, y_st);
			x++;
		}
		y++;
	}
}

void	init_img(void)
{
	t_fr	fr;
	void	*img_ptr;
	int		bpp;
	int		size_line;
	int		endian;
	int		*img_data;
	
	fr.mlx_ptr = mlx_init();
	fr.win_ptr = mlx_new_window(fr.mlx_ptr, WIN_WID, WIN_HIG, "fdf");
	img_ptr = mlx_new_image(fr.mlx_ptr, WIN_WID, WIN_HIG);
	img_data = (int *)mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
	put_color_in_img(&img_data);
	mlx_put_image_to_window(fr.mlx_ptr, fr.win_ptr, img_ptr, 0, 0);
	mlx_loop(fr.mlx_ptr);
}