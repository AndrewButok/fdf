/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 11:15:00 by abutok            #+#    #+#             */
/*   Updated: 2018/02/23 15:26:18 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	line_check(t_view *view)
{
	if (errno != 0)
	{
		perror("Line creation error occurred");
		exit_x(view);
	}
}

void	readpoint_check(int r, t_list **rows, t_view *view)
{
	t_list *iter;

	iter = *rows;
	if (!r)
	{
		ft_putendl_fd("Error: Wrong data format.", 2);
		iter = *rows;
		while (iter)
		{
			ft_splitedrowdel(iter->content, iter->content_size);
			iter = iter->next;
		}
		exit_x(view);
	}
}

void	check_splited_rows(t_list **rows, t_view *view)
{
	t_list	*it;

	it = *rows;
	while (it)
	{
		if (it->content == NULL)
		{
			ft_putendl_fd("Map row split error.", 2);
			it = *rows;
			while (it)
			{
				ft_splitedrowdel(it->content, it->content_size);
				it = it->next;
			}
			exit_x(view);
		}
		it = it->next;
	}
}

void	rp_check(t_view *view)
{
	if (view->rp == NULL)
	{
		ft_putendl_fd("Rotation point malloc error", 2);
		exit_x(view);
	}
}
