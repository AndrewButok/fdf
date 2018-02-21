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
	t_point	*n;
	t_list	*iter;

	while (points)
	{
		current = points->content;
		current->right = points->next != NULL ? ((t_point*)points->next->content) : NULL;

		points = points->next;
	}
}
