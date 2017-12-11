/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_wu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:26:00 by abutok            #+#    #+#             */
/*   Updated: 2017/12/06 18:03:57 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_color	set_brightness(t_color color, double brightness)
{
	if (brightness == 1)
		brightness = 0.9;
	if (brightness == 0)
		brightness = 0.1;
	color.color = color.color |
	((int)(255 * (brightness == 1 ? 0.9 : brightness)) << 24);
	return (color);
}

static void		line_putx(t_point *start, t_point *end,
							bool ck, double gradient)
{
	double	x;
	double	y;
	int		i;
	t_color	color;

	x = (double)start->x;
	y = (double)start->y;
	i = 0;
	while (x != end->x)
	{
		color.color = linear_gradient(start, end, ck, i++);
		mlx_pixel_put(g_mlx, g_win, (int)round(x),
		(int)floor(y), set_brightness(color, y - floor(y)).color);
		mlx_pixel_put(g_mlx, g_win, (int)round(x),
		(int)floor(y) + 1, set_brightness(color, 1 - y + floor(y)).color);
		x++;
		y += gradient;
	}
	mlx_pixel_put(g_mlx, g_win, end->x,
	end->y, set_brightness(end->color, 0.1).color);
	mlx_pixel_put(g_mlx, g_win, end->x,
	end->y + 1, set_brightness(end->color, 0.9).color);
}

static void		line_puty(t_point *start, t_point *end,
							bool ck, double gradient)
{
	double	x;
	double	y;
	int		i;
	t_color	color;

	x = (double)start->x;
	y = (double)start->y;
	i = 0;
	while (y != end->y)
	{
		color.color = linear_gradient(start, end, ck, i++);
		mlx_pixel_put(g_mlx, g_win, (int)floor(x),
		(int)round(y), set_brightness(color, x - floor(x)).color);
		mlx_pixel_put(g_mlx, g_win, (int)floor(x) + 1,
		(int)round(y), set_brightness(color, 1 - x + floor(x)).color);
		y++;
		x += gradient;
	}
	mlx_pixel_put(g_mlx, g_win, end->x,
	end->y, set_brightness(end->color, 0.1).color);
	mlx_pixel_put(g_mlx, g_win, end->x + 1,
	end->y, set_brightness(end->color, 0.9).color);
}

void			draw_line_antialias(t_point *start, t_point *end)
{
	double	gradient;
	bool	corner_koef;

	if (start->x == end->x || start->y == end->y)
	{
		draw_line(start, end);
		return ;
	}
	corner_koef = abs(end->x - start->x) >= abs(end->y - start->y);
	if (start->x > end->x)
		ft_swap(start, end, sizeof(t_point));
	if (!corner_koef && start->y > end->y)
		ft_swap(start, end, sizeof(t_point));
	gradient = corner_koef ? ((double)end->y - (double)start->y) /
			((double)end->x - (double)start->x) :
			((double)end->x - (double)start->x) /
			((double)end->y - (double)start->y);
	if (corner_koef)
		line_putx(start, end, corner_koef, gradient);
	else
		line_puty(start, end, corner_koef, gradient);
}
