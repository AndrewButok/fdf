/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_jobs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 14:11:25 by abutok            #+#    #+#             */
/*   Updated: 2018/02/23 15:34:52 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	button_rotate(int key, t_view *view)
{
	view->gx += key == W_KEY ? view->ospeed : 0;
	view->gx -= key == S_KEY ? view->ospeed : 0;
	view->gy += key == D_KEY ? view->ospeed : 0;
	view->gy -= key == A_KEY ? view->ospeed : 0;
	view->gz += key == E_KEY ? view->ospeed : 0;
	view->gz -= key == Q_KEY ? view->ospeed : 0;
	if (key == AU_KEY)
		view->ospeed += view->ospeed == 360 ? -360 : 1;
	if (key == AD_KEY)
		view->ospeed -= view->ospeed == 0 ? -360 : 1;
	group_rotate(view->tpoints, view->trp,
			0.0174532925 * view->gx, 0);
	group_rotate(view->tpoints, view->trp,
			0.0174532925 * view->gy, 1);
	group_rotate(view->tpoints, view->trp,
			0.0174532925 * view->gz, 2);
}

void	clone_points(t_view *view)
{
	t_list	*original;
	t_list	*clone;
	t_point	*original_point;

	original = view->points;
	while (original != NULL)
	{
		original_point = (t_point*)original->content;
		clone = ft_lstnew(original_point, sizeof(t_point));
		ft_lstadd(&view->tpoints, clone);
		original = original->next;
	}
}

void	move_to_center(t_view *view)
{
	int		x;
	int		y;
	t_list	*it;

	view->trp = (t_point*)malloc(sizeof(t_point));
	ft_memcpy(view->trp, view->rp, sizeof(t_point));
	view->trp->x = (int)(view->trp->x * view->zoom);
	view->trp->y = (int)(view->trp->y * view->zoom);
	view->trp->z = (int)(view->trp->z * view->zoom);
	x = view->x / 2 - view->trp->x;
	y = view->y / 2 - view->trp->y;
	view->trp->x += x;
	view->trp->y += y;
	it = view->tpoints;
	while (it != NULL)
	{
		((t_point*)it->content)->x += x;
		((t_point*)it->content)->y += y;
		it = it->next;
	}
}

void	move_pic(int key, t_view *view)
{
	t_list *ps;

	view->dx += key == K_KEY ? view->ospeed : 0;
	view->dx -= key == H_KEY ? view->ospeed : 0;
	view->dy += key == U_KEY ? view->ospeed : 0;
	view->dy -= key == J_KEY ? view->ospeed : 0;
	ps = view->tpoints;
	view->trp->x +=view->dx;
	view->trp->y +=view->dy;
	while (ps != NULL)
	{
		((t_point*)ps->content)->x += view->dx;
		((t_point*)ps->content)->y += view->dy;
		ps = ps->next;
	}
}

void	button_zoom(int key, t_view *view)
{
	view->zoom *= key == PLUS_KEY ? 2.0 : 1;
	view->zoom /= key == MINUS_KEY ? 2.0 : 1;
	zoom(view);
}
