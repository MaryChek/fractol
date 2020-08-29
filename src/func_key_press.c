/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_key_press.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 18:15:39 by rtacos            #+#    #+#             */
/*   Updated: 2020/08/04 20:33:11 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	move_map(int key)
{
	int	a;

	a = 10;
	if (key == 123)
		g_fr.x_st -= a;
	if (key == 124)
		g_fr.x_st += a;
	if (key == 125)
		g_fr.y_st += a;
	if (key == 126)
		g_fr.y_st -= a;
}

void	change_zoom_and_iter(int key)
{
	if (key == 27)
		g_zoom += 0.00004;
	else if (key == 24)
		g_zoom -= 0.00004;
	else if (key == 69)
		g_iter_max += 80;
	else
		g_iter_max -= 80;
}

int		key_press(int key)
{
	if (key != 53)
	{
		if (key >= 123 && key < 127)
			move_map(key);
		if (key == 27 || key == 69 || key == 78
		|| (key == 24 && (g_zoom * g_zoom / 3240000) < 14))
			change_zoom_and_iter(key);
		// if (key >= 82 && key <= 92 && key != 90)
		// 	rotation(fdf, key);
		// if (key == 6 || key == 7 || key == 16 || key == 34)
		// 	projection(key, fdf);
		mlx_clear_window(g_fr.mlx_ptr, g_fr.win_ptr);
		print_fract(&g_fr.img_data, g_fr.check_pix_iter);
		mlx_put_image_to_window(g_fr.mlx_ptr, g_fr.win_ptr, g_fr.img_ptr, 0, 0);
	}
	else
		exit(0);
	return (0);
}