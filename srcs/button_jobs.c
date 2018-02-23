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
	int	axis;
	int sign;

	axis = 3;
	axis = (key == W_KEY || key == S_KEY) ? 0 : axis;
	axis = (key == A_KEY || key == D_KEY) ? 1 : axis;
	axis = (key == Q_KEY || key == E_KEY) ? 2 : axis;
	sign = key == Q_KEY || key == S_KEY || key == A_KEY ? -1 : 1;
	if (key == AU_KEY)
		view->ospeed += view->ospeed == 360 ? -360 : 1;
	if (key == AD_KEY)
		view->ospeed -= view->ospeed == 0 ? -360 : 1;
	group_rotate(view->points, view->rp,
			0.01745 * sign * view->ospeed, axis);
}
