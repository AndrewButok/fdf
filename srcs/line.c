/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 17:40:00 by abutok            #+#    #+#             */
/*   Updated: 2017/12/11 17:40:00 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_line	*get_line(t_point *start, t_point *end, t_view *view)
{
	t_line	*result;

	errno = 0;
	result = (t_line*)malloc(sizeof(t_line));
	line_check(view);
	memreg(&(view->mem), result);
	errno = 0;
	result->start = (t_point*)malloc(sizeof(t_point));
	line_check(view);
	memreg(&(view->mem), result->start);
	errno = 0;
	result->end = (t_point*)malloc(sizeof(t_point));
	line_check(view);
	memreg(&(view->mem), result->end);
	ft_memcpy(result->start, start, sizeof(t_point));
	ft_memcpy(result->end, end, sizeof(t_point));
	return (result);
}

void	free_line(t_line **line, t_view *view)
{
	memregdel(&(view->mem),(*line)->start);
	free((*line)->start);
	memregdel(&(view->mem),(*line)->end);
	free((*line)->end);
	memregdel(&(view->mem), *line);
	free(*line);
}