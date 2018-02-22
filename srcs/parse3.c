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

	while (points)
	{
		current = points->content;
		current->right = points->next != NULL ? ((t_point*)points->next->content) : NULL;
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
