/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 17:15:57 by rtacos            #+#    #+#             */
/*   Updated: 2020/09/11 22:05:21 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

char	*selection_of_fractol(int num_fract)
{
	if (num_fract == MANDELBROT)
		return (MANDELBROT_SRC);
	if (num_fract == JULIA)
		return (JULIA_SRC);
	if (num_fract == BURN_SHIP)
		return (BURN_SHIP_SRC);
	if (num_fract == JULIA_BR_SH)
		return (JULIA_BR_SH_SRC);
	if (num_fract == FISH)
		return (FISH_SRC);
	if (num_fract == JUL_FISH)
		return (JUL_FISH_SRC);
	return (NULL);
}

void	init_img(t_fr *frac)
{
	int		bpp;
	int		size_line;
	int		endian;

	bpp = 32;
	size_line = WIN_WID;
	endian = 0;
	frac->mlx_ptr = mlx_init();
	frac->win_ptr = mlx_new_window(frac->mlx_ptr, WIN_WID, WIN_HIG, "fractol");
	frac->img_ptr = mlx_new_image(frac->mlx_ptr, WIN_WID, WIN_HIG);
	frac->img_data = (int *)mlx_get_data_addr(frac->img_ptr,
												&bpp, &size_line, &endian);
	frac->help = 0;
}

void	init_ptr_fr(t_pft init_fr[6])
{
	init_fr[0] = &init_mandelbrot;
	init_fr[1] = &init_julia;
	init_fr[2] = &init_burn_ship;
	init_fr[3] = &init_jul_burn_ship;
	init_fr[4] = &init_fish;
	init_fr[5] = &init_jul_fish;
}

int		init_fractal(char *fract, t_pft init_fr[6], t_fr *frac)
{
	init_ptr_fr(init_fr);
	if (!ft_strcmp(fract, "Mandelbrot"))
		return ((init_fr[0](frac)));
	else if (!ft_strcmp(fract, "Julia"))
		return ((init_fr[1](frac)));
	else if (!ft_strcmp(fract, "Burn_ship"))
		return ((init_fr[2](frac)));
	else if (!ft_strcmp(fract, "Jul_Burn_ship"))
		return ((init_fr[3](frac)));
	else if (!ft_strcmp(fract, "Fish"))
		return ((init_fr[4](frac)));
	else if (!ft_strcmp(fract, "Jul_fish"))
		return ((init_fr[5](frac)));
	return (0);
}

int		main(int ac, char **av)
{
	t_data	data;

	if (ac == 2 && init_fractal(av[1], data.init_fr, &data.frac))
	{
		init_img(&data.frac);
		init_cl(&data.frac.cl, data.frac.img_data);
		run_cl(&data.frac);
		mlx_hook(data.frac.win_ptr, 2, 1L << 0, key_press, &data);
		mlx_hook(data.frac.win_ptr, 4, 1L << 0, mouse_press, &data.frac);
		mlx_hook(data.frac.win_ptr, 6, 1L << 0, mouse_move, &data.frac);
		mlx_hook(data.frac.win_ptr, 17, 0, clos_e, 0);
		mlx_loop(data.frac.mlx_ptr);
	}
	else
		write_usage();
	return (0);
}
