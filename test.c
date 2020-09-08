#include "../includes/ft_fractol.h"

int				get_color(t_color rgb)
{
	int clr;

	clr = (int)(rgb.r * 255) << 16;
	clr += (int)(rgb.g * 255) << 8;
	clr += (int)(rgb.b * 255);
	return (clr);
}

void	print_img()
{
	int i;

	i = -1;
	while (++i < (WIN_HIG * WIN_WID))
	{
	int			iter;
	double		x_n;
	double		x;
	double		y;
	double		col;
	double		y_st;
	double		x_st;
	t_color		rgb;

	x = 0;
	y = 0;
	x_st = (double)(((i % WIN_WID) + g_cl.x_shift) * g_fr.zoom + g_fr.mv_mouse.x);
	y_st = (double)(((i / WIN_WID) + g_cl.y_shift) * g_fr.zoom + g_fr.mv_mouse.y);
	iter = -1;
	if (((i % WIN_WID) - WIN_WID/2) == g_fr.mouse.x && ((i / WIN_WID) - WIN_HIG/2) == g_fr.mouse.y)
	{
		int a = 2;
		a++;
	}
	while ((x * x + y * y) <= 200.00 && ++iter < g_fr.iter_max)
	{
		x_n = x;
		x = x_n * x_n - y * y + x_st;
		y = 2 * x_n * y + y_st;
	}
	col = (double)(iter - log2(log2((x * x) + (y * y))) + 5.0);
	if (iter != g_fr.iter_max)
	{
		rgb.r = 0.5 + 0.5 * cos(0.5 * col + (9.5 * g_fr.color));
		rgb.g = 0.5 + 0.5 * cos(0.5 * col + (19.5 * g_fr.color));
		rgb.b = 0.5 + 0.5 * cos(0.5 * col + (18.8 * g_fr.color));
		g_fr.img_data[i] = get_color(rgb);
	}
	else
		g_fr.img_data[i] = 0;
	}
}