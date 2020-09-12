/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_help.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 17:17:17 by rtacos            #+#    #+#             */
/*   Updated: 2020/09/12 17:37:44 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	put_str_help_2(void *mlx_ptr, void *win_ptr, int col)
{
	mlx_string_put(mlx_ptr, win_ptr, 10, 147, col,
										"______________________________");
	mlx_string_put(mlx_ptr, win_ptr, 80, 165, col,
										"of ITERATIONS (while scaling):");
	mlx_string_put(mlx_ptr, win_ptr, 70, 167, col,
									"________________________________");
	mlx_string_put(mlx_ptr, win_ptr, 20, 185, col, "[ 'R' ]");
	mlx_string_put(mlx_ptr, win_ptr, 20, 210, col, "COLOR CHANGING:");
	mlx_string_put(mlx_ptr, win_ptr, 10, 212, col, "_________________");
	mlx_string_put(mlx_ptr, win_ptr, 20, 230, col,
								"[ '+' and '-' (on the left panel) ]");
	mlx_string_put(mlx_ptr, win_ptr, 20, 255, col, "FRACTAL SWITCHING:");
	mlx_string_put(mlx_ptr, win_ptr, 10, 257, col, "____________________");
	mlx_string_put(mlx_ptr, win_ptr, 20, 275, col,
						"[ 0 - 1 - 2 - 3 - 4 - 5 (on the right panel)]");
}

void	put_str_help(void *mlx_ptr, void *win_ptr, int help, int col)
{
	if (help)
	{
		mlx_string_put(mlx_ptr, win_ptr, 20, 10, col, "MOVEMENT:");
		mlx_string_put(mlx_ptr, win_ptr, 10, 12, col, "_______________");
		mlx_string_put(mlx_ptr, win_ptr, 20, 30, col,
					"[ up arrow, down arrow, right arrow, left arrow ]");
		mlx_string_put(mlx_ptr, win_ptr, 20, 55, col, "ZOOMING:");
		mlx_string_put(mlx_ptr, win_ptr, 10, 57, col, "__________");
		mlx_string_put(mlx_ptr, win_ptr, 20, 75, col, "[ mouse scroll ]");
		mlx_string_put(mlx_ptr, win_ptr, 20, 100, col,
										"Change the number of ITERATIONS:");
		mlx_string_put(mlx_ptr, win_ptr, 10, 102, col,
										"__________________________________");
		mlx_string_put(mlx_ptr, win_ptr, 20, 120, col,
									"[ '+' and '-' (on the right panel) ]");
		mlx_string_put(mlx_ptr, win_ptr, 20, 145, col,
											"Run AUTO-changing the number");
		put_str_help_2(mlx_ptr, win_ptr, col);
	}
	else
		mlx_string_put(mlx_ptr, win_ptr, 20, 10, col, "Push 'H' for Help-list");
}
