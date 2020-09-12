#include "open_cl.h"

int				get_color(t_color rgb)
{
	int clr;

	clr = (int)(rgb.r * 255) << 16;
	clr += (int)(rgb.g * 255) << 8;
	clr += (int)(rgb.b * 255);
	return (clr);
}

__kernel void	check_iter(__global int *img, int color, int win_wid, int win_hig,
					double iter_max, double zoom, int y_shift, int x_shift, t_coord mouse)
{
	int			iter;
	double		tmp;
	double		x;
	double		y;
	double		col;
	double		y_st;
	double		x_st;
	t_color		rgb;
	int			gid;

	x = 0;
	y = 0;
	gid = get_global_id(0);
	x_st = (double)(((gid % win_wid) + x_shift) * zoom + mouse.x);
	y_st = (double)(((gid / win_wid) + y_shift) * zoom + mouse.y);
	iter = -1;
	while ((x * x + y * y) <= 200.00 && ++iter < (int)iter_max)
	{
		tmp = x;
		x = tmp * tmp - y * y + x_st;
		y = 2 * tmp * y + y_st;
	}
	col = (double)(iter - log2(log2((x * x) + (y * y))) + 5.0);
	if (iter != (int)iter_max)
	{
		rgb.r = 0.5 + 0.5 * cos(0.5 * col + (9.5 * color));
		rgb.g = 0.5 + 0.5 * cos(0.5 * col + (19.5 * color));
		rgb.b = 0.5 + 0.5 * cos(0.5 * col + (18.8 * color));
		img[gid] = get_color(rgb);
	}
	else
		img[gid] = 0;
}
