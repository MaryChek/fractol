/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 17:15:57 by rtacos            #+#    #+#             */
/*   Updated: 2020/09/08 19:49:58 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	cl_error(char *error_mess)
{
	ft_putstr_fd(error_mess, 1);
	exit(0);
}

void	init_img(void)
{
	int		bpp;
	int		size_line;
	int		endian;

	g_fr.color = 0x7403dd;
	g_fr.iter_max = 200;
	g_cl.y_shift = 0;
	g_cl.x_shift = 0;
	g_fr.zoom = (double)(WIN_HIG > WIN_WID ? 2.5 / WIN_WID : 2.5 / WIN_HIG);
	g_fr.mouse.x = 0.0;
	g_fr.mouse.y = 0.0;
	g_fr.mlx_ptr = mlx_init();
	g_fr.win_ptr = mlx_new_window(g_fr.mlx_ptr, WIN_WID, WIN_HIG, "fractol");
	g_fr.img_ptr = mlx_new_image(g_fr.mlx_ptr, WIN_WID, WIN_HIG);
	g_fr.img_data = (int *)mlx_get_data_addr(g_fr.img_ptr, &bpp, &size_line, &endian);
	g_fr.mv_mouse.x = - (WIN_WID / 2) * g_fr.zoom;
	g_fr.mv_mouse.y = - (WIN_HIG / 2) * g_fr.zoom;
	g_fr.speed_zm = 1.055;
	g_fr.button_jul = 0;
	g_fr.mouse.y = 0;
	g_fr.mouse.x = 0;
}

int		init_fractal(char *fract)
{
	int		ret;

	ret = 1;
	if (!ft_strcmp(fract, "Mandelbrot"))
		g_fr.num_fract = MANDELBROT;
	else if (!ft_strcmp(fract, "Julia"))
		g_fr.num_fract = JULIA;
	else
		ret = 0;
	return (ret);
}

int		main(int ac, char **av)
{
	if (ac == 2 && init_fractal(av[1]))
	{
		init_img();
		init_cl();
		run_cl();
		mlx_put_image_to_window(g_fr.mlx_ptr, g_fr.win_ptr, g_fr.img_ptr, 0, 0);
		mlx_hook(g_fr.win_ptr, 2, 1L << 0, key_press, 0);
		mlx_hook(g_fr.win_ptr, 4, 1L << 0, mouse_press, 0);
		mlx_hook(g_fr.win_ptr, 6, 1L << 0, mouse_move, 0);
		mlx_loop(g_fr.mlx_ptr);
	}
	else
		write(1, "usage: ./fractol name_fractal\n\nName_fractal:\n\t- Mandelbrot\n\t- Julia", 67);
	return (0);
}
