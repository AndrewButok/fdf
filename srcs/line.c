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

#include <stdio.h>
#include "fdf.h"

t_line	*get_line(t_point *start, t_point *end)
{
	t_line	*result;

	errno = 0;
	result = (t_line*)malloc(sizeof(t_line));
	if (errno)
		perror("Line creation error");
	errno = 0;
	result->start = (t_point*)malloc(sizeof(t_point));
	result->end = (t_point*)malloc(sizeof(t_point));
	if (errno)
		perror("Line creation error");
	ft_memcpy(result->start, start, sizeof(t_point));
	ft_memcpy(result->end, end, sizeof(t_point));
	return (result);
}

void	*free_line(t_line **line)
{
	free((*line)->start);
	free((*line)->end);
	free(*line);
}