#include "open_cl.h"

int				get_color(t_color rgb)
{
	int clr;

	clr = (int)(rgb.r * 255) << 16;
	clr += (int)(rgb.g * 255) << 8;
	clr += (int)(rgb.b * 255);
	return (clr);
}

double			pow(double a, int i)
{
	
	return ()
}

__kernel void	check_iter(__global int *img, int color, int win_wid, int win_hig,
					int iter_max, double zoom, int y_shift, int x_shift, t_coord mouse)
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
	double		z;

	x = 0;
	y = 0;
	gid = get_global_id(0);
	x_st = (double)(((gid % win_wid) + x_shift) * zoom + mouse.x);
	y_st = (double)(((gid / win_wid) + y_shift) * zoom + mouse.y);
	iter = -1;
	z = x_st + y_st;
	while (pow(z, 3) <= 200.00 && ++iter < iter_max)
	{
		tmp = z;
		z = tmp - pow(tmp, 3) / (3 * pow(tmp, 2));
	}
	col = (double)(iter - log2(log2((x * x) + (y * y))) + 5.0);
	if (iter != iter_max)
	{
		rgb.r = 0.5 + 0.5 * cos(0.5 * col + (9.5 * color));
		rgb.g = 0.5 + 0.5 * cos(0.5 * col + (19.5 * color));
		rgb.b = 0.5 + 0.5 * cos(0.5 * col + (18.8 * color));
		img[gid] = get_color(rgb);
	}
	else
		img[gid] = 0;
}
