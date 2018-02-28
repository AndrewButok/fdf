/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 14:23:00 by abutok            #+#    #+#             */
/*   Updated: 2018/02/23 15:26:04 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	find_neighbours(t_list *points, size_t rowsize)
{
	t_point	*current;
	t_list	*iter;
	size_t	l;
	size_t	rl;

	rl = 0;
	while (points)
	{
		current = points->content;
		current->right = (points->next != NULL && rl != rowsize - 1) ?
				((t_point*)points->next->content) : NULL;
		l = 0;
		iter = points;
		while (l++ < rowsize && iter != NULL)
			iter = iter->next;
		current->bottom = (iter == NULL) ? NULL : (t_point*)(iter->content);
		points = points->next;
		rl = rl == rowsize - 1 ? 0 : rl + 1;
	}
}

int		check_num(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void	select_rp(t_view *view)
{
	t_list *points;

	points = view->points;
	if (points == NULL)
		return ;
	view->rp = (t_point*)malloc(sizeof(t_point));
	rp_check(view);
	view->rp->x = ((t_point*)points->content)->x;
	view->rp->y = ((t_point*)points->content)->y;
	view->rp->z = ((t_point*)points->content)->z;
	while (points)
	{
		if (((t_point*)points->content)->x > view->rp->x)
			view->rp->x = ((t_point*)points->content)->x;
		if (((t_point*)points->content)->z > view->rp->z)
			view->rp->z = ((t_point*)points->content)->z;
		if (((t_point*)points->content)->y > view->rp->y)
			view->rp->y = ((t_point*)points->content)->y;
		points = points->next;
	}
	view->rp->x /= 2;
	view->rp->y /= 2;
	view->rp->z /= 2;
}
