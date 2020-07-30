/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 17:15:57 by rtacos            #+#    #+#             */
/*   Updated: 2020/07/30 20:11:52 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	print_fract(void)
{
	print_mandelbr();
}

int		init_mandelbr(void)
{
	return (MANDELBROT);
}

int		init_fractal(char *fract)
{
	if (!ft_strcmp(fract, "Mandelbrot"))
			return (init_mandelbr());
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		init_img();
		init_fractal(av[1]);
		print_fract();
	}
	else
	{
		write(1, "usage: ./fractol name_fractal\n\nName_fractal:\n\t- Mandelbrot", 58);
	}
	return (0);
}