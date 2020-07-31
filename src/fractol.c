/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 17:15:57 by rtacos            #+#    #+#             */
/*   Updated: 2020/07/31 17:32:07 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	print_fract(int **img_data)
{
	print_mandelbr(img_data);
}

int		init_mandelbr(void)
{
	return (MANDELBROT);
}

int		init_fractal(char *fract)
{
	if (!ft_strcmp(fract, "Mandelbrot"))
			return (init_mandelbr());
	return 0;
}

int		main(int ac, char **av)
{
	t_fr	fr;
	int		*img_data;
	void	*img_ptr = NULL;
	
	
	if (ac == 2)
	{
		init_img(&fr, &img_data, &img_ptr);
		init_fractal(av[1]);
		print_fract(&img_data);
		mlx_put_image_to_window(fr.mlx_ptr, fr.win_ptr, img_ptr, 0, 0);
		mlx_loop(fr.mlx_ptr);
	}
	else
	{
		write(1, "usage: ./fractol name_fractal\n\nName_fractal:\n\t- Mandelbrot", 58);
	}
	return (0);
}