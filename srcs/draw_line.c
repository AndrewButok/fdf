/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 15:24:00 by abutok            #+#    #+#             */
/*   Updated: 2017/12/06 18:03:57 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include <mlx_color.h>
#include "fdf.h"

static void		line_put(t_point *start, t_point *end, bool ck, double gradient)
{
	double	x;
	double	y;
	int		i;
	t_color	color;

	x = (double)start->x;
	y = (double)start->y;
	i = 0;
	if (ck)
		while (x != end->x)
		{
			color.color = linear_gradient(start, end, ck, i++);
			mlx_pixel_put(g_mlx, g_win, (int)x++,
					(int)round(y += gradient), color.color);
		}
	else
		while (y != end->y)
		{
			color.color = linear_gradient(start, end, ck, i++);
			mlx_pixel_put(g_mlx, g_win, (int)round(x += gradient),
					(int)y++, color.color);
		}
}

void			draw_line(t_point *start, t_point *end)
{
	double	gradient;
	bool	corner_koef;

	corner_koef = abs(end->x - start->x) >= abs(end->y - start->y);
	if (start->x > end->x)
		ft_swap(start, end, sizeof(t_point));
	if (!corner_koef && start->y > end->y)
		ft_swap(start, end, sizeof(t_point));
	gradient = corner_koef ? ((double)end->y - (double)start->y) /
			((double)end->x - (double)start->x) :
			((double)end->x - (double)start->x) /
			((double)end->y - (double)start->y);
	line_put(start, end, corner_koef, gradient);
}
