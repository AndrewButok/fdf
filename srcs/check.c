/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 11:15:00 by abutok            #+#    #+#             */
/*   Updated: 2017/12/23 11:15:00 by abutok           ###   ########.fr       */
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
	if (!r)
	{
		ft_putendl_fd("Error: Wrong data format.", 2);
		ft_lstdel(rows, &ft_splitedrowdel);
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
			ft_lstdel(rows, &ft_splitedrowdel);
			exit_x(view);
		}
		it = it->next;
	}
}
