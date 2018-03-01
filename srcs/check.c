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

void	line_check(t_line **line, t_view *view)
{
	if (errno != 0)
	{
		free((*line)->start);
		free((*line)->end);
		free(*line);
		*line = NULL;
		perror("Line creation error occurred");
		exit_x(view);
	}
}

void	readpoint_check(int r, t_list **rows, t_view *view)
{
	if (!r)
	{
		ft_putendl_fd("Error: Wrong data format.", 2);
		ft_lstdelc(rows, &ft_splitedrowdel);
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
			ft_lstdelc(rows, &ft_splitedrowdel);
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

void	check_isempty(t_view *view)
{
	if (view->rp == NULL || view->points->next == NULL)
	{
		ft_putendl_fd("Map is empty or have only one point.", 2);
		exit_x(view);
	}
}
