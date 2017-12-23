/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 12:32:00 by abutok            #+#    #+#             */
/*   Updated: 2017/12/23 12:32:00 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_point *ps, t_point *p0, double l)
{
	double ny;
	double nz;

	ny = ((ps->y - p0->y) * cos(l) + (ps->z - p0->z) * sin(l) + p0->y);
	nz = ((ps->z - p0->z) * cos(l) - (ps->y - p0->y) * sin(l) + p0->z);
	ps->y = (int)round(ny);
	ps->z = (int)round(nz);
}

void	rotate_y(t_point *ps, t_point *p0, double l)
{
	double nx;
	double nz;

	nx = ((ps->x - p0->x) * cos(l) + (ps->z - p0->z) * sin(l) + p0->x);
	nz = ((ps->z - p0->z) * cos(l) - (ps->x - p0->x) * sin(l) + p0->z);
	ps->x = (int)round(nx);
	ps->z = (int)round(nz);
}

void	rotate_z(t_point *ps, t_point *p0, double l)
{
	double ny;
	double nx;

	nx = ((ps->x - p0->x) * cos(l) - (ps->y - p0->y) * sin(l) + p0->x);
	ny = ((ps->y - p0->y) * cos(l) + (ps->x - p0->x) * sin(l) + p0->y);
	ps->x = (int)round(nx);
	ps->y = (int)round(ny);
}