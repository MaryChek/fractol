/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 17:15:57 by rtacos            #+#    #+#             */
/*   Updated: 2020/08/29 18:53:06 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	init_mandelbr(void)
{
	g_fr.check_pix_iter = check_iter_mandelbr;
}

void	init_fractal(char *fract)
{
	if (!ft_strcmp(fract, "Mandelbrot"))
			init_mandelbr();
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		init_img();
		init_cl();
		init_fractal(av[1]);
		print_fract(&g_fr.img_data, g_fr.check_pix_iter);
		mlx_put_image_to_window(g_fr.mlx_ptr, g_fr.win_ptr, g_fr.img_ptr, 0, 0);
		mlx_hook(g_fr.win_ptr, 2, 1L << 0, key_press, 0);
		mlx_loop(g_fr.mlx_ptr);
	}
	else
		write(1, "usage: ./fractol name_fractal\n\nName_fractal:\n\t- Mandelbrot", 58);
	return (0);
}