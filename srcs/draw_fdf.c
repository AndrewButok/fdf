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

void	rm_ptslist(t_list **list, t_view *view)
{
	t_list *lst;
	t_list *buf;

	lst = *list;
	while (lst)
	{
		buf = lst->next;
		memregdel(&view->mem, lst->content);
		free(lst->content);
		memregdel(&view->mem, lst);
		free(lst);
		lst = buf;
	}
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
			free_line(&line, view);
		}
		if (cp->bottom != NULL)
		{
			line = get_line(cp, cp->bottom, view);
			view->draw_line(line, view);
			free_line(&line, view);
		}
		points = points->next;
	}
	//todo list destr
	rm_ptslist(&view->tpoints, view);
	memregdel(&view->mem, view->trp);
	free(view->trp);
}

