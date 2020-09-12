/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_jul_fracts.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 03:45:22 by rtacos            #+#    #+#             */
/*   Updated: 2020/09/11 21:20:40 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int		init_julia(t_fr *frac)
{
	frac->zoom = (double)(WIN_HIG > WIN_WID ? 2.9 / WIN_WID : 2.9 / WIN_HIG);
	frac->mv_mouse.x = -(WIN_WID / 2) * frac->zoom;
	frac->mv_mouse.y = -(WIN_HIG / 2) * frac->zoom;
	frac->cl.y_shift = 0;
	frac->cl.x_shift = 0;
	frac->color = 0x17fb8b4d;
	frac->mouse.y = 525.00;
	frac->mouse.x = 1095.0;
	frac->iter_max = 200.0;
	frac->num_fract = JULIA;
	frac->speed_zm = 1.04;
	frac->button_jul = 0;
	frac->iter_up_auto = 0;
	frac->clr_txt = 0x0af7ff;
	return (1);
}

int		init_jul_burn_ship(t_fr *frac)
{
	frac->zoom = (double)(WIN_HIG > WIN_WID ? 3.4 / WIN_WID : 3.4 / WIN_HIG);
	frac->mv_mouse.x = -(WIN_WID / 2) * frac->zoom;
	frac->mv_mouse.y = -(WIN_HIG / 2) * frac->zoom;
	frac->cl.y_shift = 0;
	frac->cl.x_shift = 0;
	frac->color = 0x346d5ad;
	frac->mouse.y = 51.0;
	frac->mouse.x = 1307.00;
	frac->iter_max = 35.0;
	frac->num_fract = JULIA_BR_SH;
	frac->speed_zm = 1.04;
	frac->button_jul = 0;
	frac->iter_up_auto = 0;
	frac->clr_txt = 0x10cc4f;
	return (1);
}

int		init_jul_fish(t_fr *frac)
{
	frac->zoom = (double)(WIN_HIG > WIN_WID ? 3.4 / WIN_WID : 3.4 / WIN_HIG);
	frac->mv_mouse.x = -(WIN_WID / 2) * frac->zoom;
	frac->mv_mouse.y = -(WIN_HIG / 2) * frac->zoom;
	frac->cl.y_shift = 0;
	frac->cl.x_shift = 0;
	frac->color = 0x9964f435;
	frac->mouse.y = 542.0;
	frac->mouse.x = 1181.0;
	frac->iter_max = 200.0;
	frac->num_fract = JUL_FISH;
	frac->speed_zm = 1.04;
	frac->button_jul = 0;
	frac->iter_up_auto = 0;
	frac->clr_txt = 0x10cc4f;
	return (1);
}
