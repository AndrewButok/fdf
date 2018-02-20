/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 14:37:00 by abutok            #+#    #+#             */
/*   Updated: 2018/02/20 14:37:00 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_rows(t_list **rows, t_view *view)
{
	t_list 	*iter;
	size_t 	cv;

	iter = *rows;
	cv = iter->content_size;
	while (iter)
	{
		if (cv != iter->content_size)
		{
			ft_putendl("Wrong map size.");
			ft_lstdel(rows, &ft_splitedrowdel);
			exit_x(view);
		}
		iter = iter->next;
	}
}
