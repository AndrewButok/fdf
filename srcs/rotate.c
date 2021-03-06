/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 12:32:00 by abutok            #+#    #+#             */
/*   Updated: 2018/02/23 15:28:09 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotate_x(t_point *ps, t_point *p0, double l)
{
	double ny;
	double nz;

	ny = ((ps->y - p0->y) * cos(l) + (ps->z - p0->z) * sin(l) + p0->y);
	nz = ((ps->z - p0->z) * cos(l) - (ps->y - p0->y) * sin(l) + p0->z);
	ps->y = (int)round(ny);
	ps->z = (int)round(nz);
}

static void	rotate_y(t_point *ps, t_point *p0, double l)
{
	double nx;
	double nz;

	nx = ((ps->x - p0->x) * cos(l) + (ps->z - p0->z) * sin(l) + p0->x);
	nz = ((ps->z - p0->z) * cos(l) - (ps->x - p0->x) * sin(l) + p0->z);
	ps->x = (int)round(nx);
	ps->z = (int)round(nz);
}

static void	rotate_z(t_point *ps, t_point *p0, double l)
{
	double ny;
	double nx;

	nx = ((ps->x - p0->x) * cos(l) - (ps->y - p0->y) * sin(l) + p0->x);
	ny = ((ps->y - p0->y) * cos(l) + (ps->x - p0->x) * sin(l) + p0->y);
	ps->x = (int)round(nx);
	ps->y = (int)round(ny);
}

void		group_rotate(t_list *ps, t_point *p0, double angle, int axis)
{
	void (*rotate)(t_point*, t_point*, double);

	if (axis == 0)
		rotate = &rotate_x;
	else if (axis == 1)
		rotate = &rotate_y;
	else if (axis == 2)
		rotate = &rotate_z;
	else
		return ;
	while (ps != NULL)
	{
		(*rotate)((t_point*)ps->content, p0, angle);
		ps = ps->next;
	}
}

void		zoom(t_view *view)
{
	t_list	*ps;
	double	zoom;

	ps = view->tpoints;
	zoom = view->zoom < 0 ? 1.0 / abs(view->zoom) : view->zoom;
	while (ps != NULL)
	{
		((t_point*)ps->content)->x = (int)(((t_point*)ps->content)->x *
				zoom);
		((t_point*)ps->content)->y = (int)(((t_point*)ps->content)->y *
				zoom);
		((t_point*)ps->content)->z = (int)(((t_point*)ps->content)->z *
				zoom);
		ps = ps->next;
	}
}
