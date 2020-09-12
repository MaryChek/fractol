/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fracts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 17:06:59 by rtacos            #+#    #+#             */
/*   Updated: 2020/09/11 21:20:31 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int		init_mandelbrot(t_fr *frac)
{
	frac->zoom = (double)(WIN_HIG > WIN_WID ? 2.5 / WIN_WID : 2.5 / WIN_HIG);
	frac->mv_mouse.x = -(WIN_WID / 2) * frac->zoom;
	frac->mv_mouse.y = -(WIN_HIG / 2) * frac->zoom;
	frac->cl.y_shift = 0;
	frac->cl.x_shift = 0;
	frac->color = 0x7403dd;
	frac->mouse.y = 0;
	frac->mouse.x = 0;
	frac->iter_max = 200.0;
	frac->num_fract = MANDELBROT;
	frac->speed_zm = 1.04;
	frac->button_jul = 0;
	frac->iter_up_auto = 0;
	frac->clr_txt = 0x10cc4f;
	return (1);
}

int		init_burn_ship(t_fr *frac)
{
	frac->zoom = (double)(WIN_HIG > WIN_WID ? 2.9 / WIN_WID : 2.9 / WIN_HIG);
	frac->mv_mouse.x = -(WIN_WID / 2) * frac->zoom;
	frac->mv_mouse.y = -(WIN_HIG / 2) * frac->zoom;
	frac->cl.y_shift = -150;
	frac->cl.x_shift = 0;
	frac->color = 0xca69f909;
	frac->mouse.y = 0;
	frac->mouse.x = 0;
	frac->iter_max = 20.0;
	frac->num_fract = BURN_SHIP;
	frac->speed_zm = 1.04;
	frac->button_jul = 0;
	frac->iter_up_auto = 0;
	frac->clr_txt = 0x10cc4f;
	return (1);
}

int		init_fish(t_fr *frac)
{
	frac->zoom = (double)(WIN_HIG > WIN_WID ? 2.4 / WIN_WID : 2.4 / WIN_HIG);
	frac->mv_mouse.x = -(WIN_WID / 2) * frac->zoom;
	frac->mv_mouse.y = -(WIN_HIG / 2) * frac->zoom;
	frac->cl.y_shift = 0;
	frac->cl.x_shift = 0;
	frac->color = 0xc09c2b45;
	frac->mouse.y = 0;
	frac->mouse.x = 0;
	frac->iter_max = 200.0;
	frac->num_fract = FISH;
	frac->speed_zm = 1.04;
	frac->button_jul = 0;
	frac->iter_up_auto = 0;
	frac->clr_txt = 0x10cc4f;
	return (1);
}
