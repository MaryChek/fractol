/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_cl.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 17:56:43 by rtacos            #+#    #+#             */
/*   Updated: 2020/09/12 17:22:47 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPEN_CL_H
# define OPEN_CL_H

typedef struct	s_color
{
	double	r;
	double	g;
	double	b;
}				t_color;

typedef	struct	s_coord
{
	double	x;
	double	y;
}				t_coord;

int				get_color(t_color color);

#endif
