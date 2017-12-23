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

void	rotate_x(t_point *point, double l)
{
	point->y = (int)round(point->y * cos(l) + point->z * sin(l));
	point->z = (int)round(point->z * cos(l) - point->y * sin(l));
}

void	rotate_y(t_point *point, double l)
{
	point->x = (int)round(point->x * cos(l) + point->z * sin(l));
	point->z = (int)round(point->z * cos(l) - point->x * sin(l));
}

void	rotate_z(t_point *point, double l)
{
	point->x = (int)round(point->x * cos(l) - point->y * sin(l));
	point->y = (int)round(point->y * cos(l) + point->x * sin(l));
}