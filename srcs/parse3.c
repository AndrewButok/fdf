/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 14:23:00 by abutok            #+#    #+#             */
/*   Updated: 2018/02/21 14:23:00 by abutok           ###   ########.fr       */
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
		current->right = points->next != NULL && rl != rowsize - 1 ?
				((t_point*)points->next->content) : NULL;
		l = 0;
		iter = points;
		while (l < rowsize && iter)
		{
			iter = iter->next;
			l++;
		}
		if (iter != NULL)
			current->bottom = (t_point*)iter->content;
		else
			current->bottom = NULL;
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
	view->rp = (t_point*)malloc(sizeof(t_point));
	if (view->rp == NULL)
	{
		ft_putendl_fd("Error: Rotation point malloc error", 2);
		exit_x(view);
	}
	memreg(&view->mem, view->rp);
	view->rp->y = 0;
	while (points)
	{
		if (((t_point*)points->content)->x > view->rp->x)
			view->rp->x = ((t_point*)points->content)->x;
		if (((t_point*)points->content)->z > view->rp->z)
			view->rp->z = ((t_point*)points->content)->z;
		points = points->next;
	}
}
