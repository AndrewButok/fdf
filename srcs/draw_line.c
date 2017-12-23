/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 15:24:00 by abutok            #+#    #+#             */
/*   Updated: 2017/12/05 00:44:44 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			img_pixel_put(t_view *view, int x, int y, t_color color)
{
	t_color			colorb;
	int				*scene;

	if (view->endian == 1)
	{
		colorb.spectrum.alpha = color.spectrum.blue;
		colorb.spectrum.red = color.spectrum.green;
		colorb.spectrum.green = color.spectrum.red;
		colorb.spectrum.blue = color.spectrum.alpha;
	}
	else
		colorb.color = color.color;
	scene = (int*)view->scene;
	if (x >= view->x || y >= view->y ||
			x < 0 || y < 0)
		return ;
	scene[(y * view->size_line / 4) + x] = colorb.color;
}

static void		line_put(t_line *line, bool ck, double gradient, t_view *view)
{
	double	x;
	double	y;
	int		i;
	t_color color;

	x = (double)line->start->x;
	y = (double)line->start->y;
	i = 0;
	while (1)
	{
		color.color = linear_gradient(line->start, line->end, ck, i++);
		img_pixel_put(view, (ck ? (int)x : (int)round(x)),
				(ck ? (int)round(y) : (int)y),
				color);
		if ((ck && x >= line->end->x) || (!ck && y >= line->end->y))
			break ;
		x += ck ? 1 : gradient;
		y += ck ? gradient : 1;
	}
}

void			draw_line(t_line *line, t_view *view)
{
	double	gradient;
	bool	corner_koef;

	corner_koef = abs(line->end->x - line->start->x) >=
			abs(line->end->y - line->start->y);
	if (line->start->x > line->end->x)
		ft_swap(line->start, line->end, sizeof(t_point));
	if (!corner_koef && line->start->y > line->end->y)
		ft_swap(line->start, line->end, sizeof(t_point));
	gradient = corner_koef ? ((double)line->end->y - (double)line->start->y) /
			((double)line->end->x - (double)line->start->x) :
			((double)line->end->x - (double)line->start->x) /
			((double)line->end->y - (double)line->start->y);
	line_put(line, corner_koef, gradient, view);
}
