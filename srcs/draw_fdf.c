/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 11:46:00 by abutok            #+#    #+#             */
/*   Updated: 2018/02/23 11:46:00 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rm_point(void *content, size_t size)
{
	free(content);
	size = 0;
}

void	draw_fdf(t_view *view)
{
	t_list	*points;
	t_point	*cp;
	t_line	*line;

	points = view->tpoints;
	while (points != NULL)
	{
		cp = (t_point*)points->content;
		if (cp->right != NULL)
		{
			line = get_line(cp, cp->right, view);
			view->draw_line(line, view);
			free_line(&line);
		}
		if (cp->bottom != NULL)
		{
			line = get_line(cp, cp->bottom, view);
			view->draw_line(line, view);
			free_line(&line);
		}
		points = points->next;
	}
	ft_lstdel(&view->tpoints, &rm_point);
	free(view->trp);
}

