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
			double iter_max, double zoom, int y_shift, int x_shift, t_coord mouse, t_coord consts, double jul_fr)
{
	int			iter;
	double		tmp;
	double		col;
	double		y_st;
	double		x_st;
	t_color		rgb;
	int			gid;

	gid = get_global_id(0);
	consts.x = (consts.x - (win_wid / 2)) * jul_fr;
	consts.y = (consts.y - (win_hig / 2)) * jul_fr;
	x_st = (double)(((gid % win_wid) + x_shift) * zoom + mouse.x);
	y_st = (double)(((gid / win_wid) + y_shift) * zoom + mouse.y);
	iter = -1;
	while ((x_st * x_st + y_st * y_st) <= 200.00 && ++iter < (int)iter_max)
	{
		tmp = x_st;
		x_st = fabs(tmp * tmp - y_st * y_st + consts.x);
		y_st = 2 * fabs(tmp * y_st) + consts.y;
	}
	col = (double)(iter - log2(log2((x_st * x_st) + (y_st * y_st))) + 5.0);
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