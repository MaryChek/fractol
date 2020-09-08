/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_key_press.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 18:15:39 by rtacos            #+#    #+#             */
/*   Updated: 2020/09/08 19:57:44 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	move_map(int key)
{
	int	a;

	a = 10;
	if (key == 123)
		g_cl.x_shift += a;
	if (key == 124)
		g_cl.x_shift -= a;
	if (key == 125)
		g_cl.y_shift -= a;
	if (key == 126)
		g_cl.y_shift += a;
}

void	change_iter(int key)
{
	if (key == 69)
		g_fr.iter_max += 5;
	else
		g_fr.iter_max -= 5;
}

int		key_press(int key)
{
	if (key != 53)
	{
		if (key >= 123 && key < 127)
			move_map(key);
		if (key == 69 || key == 78)
			change_iter(key);
		if (key == 49)
			g_fr.color += 500 << 16 | 500 << 8 | 500;
		if (key == 82)
			g_fr.color -= 500 << 16 | 500 << 8 | 500;
		// if (key >= 82 && key <= 92 && key != 90)
		// 	rotation(fdf, key);
		// if (key == 6 || key == 7 || key == 16 || key == 34)
		// 	projection(key, fdf);
		mlx_clear_window(g_fr.mlx_ptr, g_fr.win_ptr);
		run_cl();
		mlx_put_image_to_window(g_fr.mlx_ptr, g_fr.win_ptr, g_fr.img_ptr, 0, 0);
	}
	else
		exit(0);
	return (0);
}

int		mouse_press(int button, int x, int y)
{
	double		mv_x;
	double		mv_y;

	mv_y = (double)(y + g_cl.y_shift);
	mv_x = (double)(x + g_cl.x_shift);
	if (button == 4 || button == 6) // приближение
	{
		g_fr.mv_mouse.x -= mv_x * g_fr.zoom * ((1.0 / g_fr.speed_zm) - 1.0);
		g_fr.mv_mouse.y -= mv_y * g_fr.zoom * ((1.0 / g_fr.speed_zm) - 1.0);
		g_fr.zoom /= g_fr.speed_zm;
	}
	if (button == 5 || button == 7)
	{
		g_fr.mv_mouse.x -= mv_x * g_fr.zoom * (g_fr.speed_zm - 1.0);
		g_fr.mv_mouse.y -= mv_y * g_fr.zoom * (g_fr.speed_zm - 1.0);
		g_fr.zoom *= g_fr.speed_zm;
	}
	if (button == 1)
		g_fr.button_jul = g_fr.button_jul == 0 ? 1 : 0;
	mlx_clear_window(g_fr.mlx_ptr, g_fr.win_ptr);
	run_cl();
	mlx_put_image_to_window(g_fr.mlx_ptr, g_fr.win_ptr, g_fr.img_ptr, 0, 0);
	return (0);
}

int		mouse_move(int x, int y)
{
	if (g_fr.button_jul == 1)
	{
		g_fr.mouse.y = (double)y;
		g_fr.mouse.x = (double)x;
	}
	mlx_clear_window(g_fr.mlx_ptr, g_fr.win_ptr);
	run_cl();
	mlx_put_image_to_window(g_fr.mlx_ptr, g_fr.win_ptr, g_fr.img_ptr, 0, 0);
	return (0);
}
