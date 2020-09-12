/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_key_press.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 18:15:39 by rtacos            #+#    #+#             */
/*   Updated: 2020/09/11 21:16:35 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	move_map_or_change_iter(int key, t_fr *frac)
{
	int	a;

	a = 13;
	if (key == 123)
		frac->cl.x_shift += a;
	else if (key == 124)
		frac->cl.x_shift -= a;
	else if (key == 125)
		frac->cl.y_shift -= a;
	else if (key == 126)
		frac->cl.y_shift += a;
	else if (key == 69)
		frac->iter_max += 3.0;
	else
		frac->iter_max -= (frac->iter_max - 9.0 > 0) ? 9.0 : 0;
}

int		key_press(int key, t_data *data)
{
	if (key != 53 && !(key >= 82 && key <= 87))
	{
		if ((key >= 123 && key < 127) || key == 69 || key == 78)
			move_map_or_change_iter(key, &data->frac);
		if (key == 24)
			data->frac.color += 500 << 16 | 500 << 8 | 500;
		if (key == 27)
			data->frac.color -= 500 << 16 | 500 << 8 | 500;
		if (key == 15)
			data->frac.iter_up_auto = data->frac.iter_up_auto == 0 ? 1 : 0;
		if (key == 4)
			data->frac.help = data->frac.help == 0 ? 1 : 0;
		draw(data->frac);
	}
	else if (key == 53)
		clear_cl(data->frac.cl, 1);
	else if (key >= 82 && key <= 87)
	{
		data->init_fr[key - 82](&data->frac);
		clear_cl(data->frac.cl, 0);
		run_cl(&data->frac);
	}
	return (0);
}

int		mouse_press(int button, int x, int y, t_fr *frac)
{
	double		mv_x;
	double		mv_y;

	mv_y = (double)(y + frac->cl.y_shift);
	mv_x = (double)(x + frac->cl.x_shift);
	if (button == 4 || button == 6)
	{
		frac->mv_mouse.x -= mv_x * frac->zoom * ((1.0 / frac->speed_zm) - 1.0);
		frac->mv_mouse.y -= mv_y * frac->zoom * ((1.0 / frac->speed_zm) - 1.0);
		frac->zoom /= frac->speed_zm;
		frac->iter_max += frac->iter_up_auto > 0 ? 0.2 : 0.0;
	}
	if (button == 5 || button == 7)
	{
		frac->mv_mouse.x -= mv_x * frac->zoom * (frac->speed_zm - 1.0);
		frac->mv_mouse.y -= mv_y * frac->zoom * (frac->speed_zm - 1.0);
		frac->zoom *= frac->speed_zm;
		frac->iter_max -= frac->iter_up_auto > 0 ? 0.2 : 0.0;
	}
	if (button == 1)
		frac->button_jul = frac->button_jul == 0 ? 1 : 0;
	draw(*frac);
	put_str_help(frac->mlx_ptr, frac->win_ptr, frac->help, frac->clr_txt);
	return (0);
}

int		mouse_move(int x, int y, t_fr *frac)
{
	if (frac->button_jul == 1)
	{
		frac->mouse.y = (double)y;
		frac->mouse.x = (double)x;
	}
	draw(*frac);
	put_str_help(frac->mlx_ptr, frac->win_ptr, frac->help, frac->clr_txt);
	return (0);
}
