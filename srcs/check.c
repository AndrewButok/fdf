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
		perror("Line creation error occurred:");
		memclear(&(view->mem));
		exit(-1);
	}
}
