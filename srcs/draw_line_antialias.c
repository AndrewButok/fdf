/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_wu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:26:00 by abutok            #+#    #+#             */
/*   Updated: 2017/11/29 15:26:00 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_color	set_brightness(t_color color, double brightness)
{
	brightness = brightness == 1 ? 0.9 : brightness;
	brightness = brightness == 0 ? 0.1 : brightness;
	color.spectrum.red *= brightness;
	color.spectrum.green *= brightness;
	color.spectrum.blue *= brightness;
	return (color);
}

static void		line_putx(t_line *line, bool ck,
		double gradient, t_view *view)
{
	double	x;
	double	y;
	int		i;
	t_color	color;

	x = (double)line->start->x;
	y = (double)line->start->y;
	i = 0;
	while (x <= line->end->x)
	{
		color.color = linear_gradient(line->start, line->end, ck, i++);
		img_pixel_put(view, (int)round(x), (int)floor(y),
				set_brightness(color, 1 - (y - floor(y))));
		img_pixel_put(view, (int)round(x), (int)floor(y) + 1,
				set_brightness(color, y - floor(y)));
		x++;
		y += gradient;
	}
	img_pixel_put(view, line->end->x, line->end->y,
			set_brightness(line->end->color, 1));
	img_pixel_put(view, line->end->x, line->end->y + 1,
			set_brightness(line->end->color, 0));
}

static void		line_puty(t_line *line, bool ck,
		double gradient, t_view *view)
{
	double	x;
	double	y;
	int		i;
	t_color	color;

	x = (double)line->start->x;
	y = (double)line->start->y;
	i = 0;
	while (y <= line->end->y)
	{
		color.color = linear_gradient(line->start, line->end, ck, i++);
		img_pixel_put(view, (int)floor(x), (int)round(y),
				set_brightness(color, 1 - (x - floor(x))));
		img_pixel_put(view, (int)floor(x) + 1, (int)round(y),
				set_brightness(color, x - floor(x)));
		y++;
		x += gradient;
	}
	img_pixel_put(view, line->end->x, line->end->y,
			set_brightness(line->end->color, 1));
	img_pixel_put(view, line->end->x + 1, line->end->y,
			set_brightness(line->end->color, 0));
}

void			draw_line_antialias(t_line *line, t_view *view)
{
	double	gradient;
	bool	corner_koef;

	if (line->start->x == line->end->x ||
			line->start->y == line->end->y)
	{
		draw_line(line, view);
		return ;
	}
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
	if (corner_koef)
		line_putx(line, corner_koef, gradient, view);
	else
		line_puty(line, corner_koef, gradient, view);
}
