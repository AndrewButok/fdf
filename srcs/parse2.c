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

size_t	check_size(t_list **rows, t_view *view)
{
	t_list	*iter;
	size_t	cv;

	iter = *rows;
	cv = iter->content_size;
	while (iter)
	{
		if (cv != iter->content_size)
		{
			ft_putendl_fd("Error: Wrong map size.", 2);
			ft_lstdelc(rows, &ft_splitedrowdel);
			exit_x(view);
		}
		iter = iter->next;
	}
	return (cv);
}

char	**split_fpoint(char *str)
{
	char *iter;

	iter = str;
	if (*iter == '-' || *iter == '+')
		iter++;
	while (*iter != ',')
		if (!ft_isdigit(*iter++))
			return (NULL);
	iter++;
	if (!(*iter == '0' && *(iter + 1) == 'x'))
		return (0);
	iter += 2;
	while (*iter)
	{
		if (!ft_isdigit(*iter) && !(*iter >= 'a' && *iter <= 'f')
			&& !(*iter >= 'A' && *iter <= 'F'))
			return (NULL);
		iter++;
	}
	return (ft_strsplit(str, ','));
}

int		get_point(char *str, size_t x, size_t z, t_view *view)
{
	char	**arr;
	t_point	*point;
	t_list	*nls;

	if ((arr = split_fpoint(str)) == NULL)
		return (0);
	point = (t_point*)malloc(sizeof(t_point));
	if (point == NULL)
		return (0);
	point->x = (int)x;
	point->z = (int)z;
	point->y = ft_atoi(arr[0]);
	point->color.color = ft_hexatoi(arr[1]);
	ft_splitedrowdel(arr, 3);
	point->right = NULL;
	point->bottom = NULL;
	nls = ft_lstnew(point, sizeof(*point));
	ft_lstadd(&(view->points), nls);
	free(point);
	return (1);
}

int		get_point_wc(char *str, size_t x, size_t z, t_view *view)
{
	t_point	*point;
	t_list	*nls;

	if (!check_num(str))
		return (0);
	point = (t_point*)malloc(sizeof(t_point));
	if (point == NULL)
		return (0);
	point->x = (int)x;
	point->z = (int)z;
	point->y = ft_atoi(str);
	point->color.color = 0xffffff;
	point->right = NULL;
	point->bottom = NULL;
	nls = ft_lstnew(point, sizeof(*point));
	ft_lstadd(&(view->points), nls);
	free(point);
	return (1);
}

void	get_points(t_list **rows, t_view *view)
{
	t_list	*iter;
	char	**arr;
	int		r;
	size_t	x;
	size_t	z;

	iter = *rows;
	z = 0;
	while (iter)
	{
		arr = (char**)iter->content;
		x = 0;
		while (x < iter->content_size)
		{
			if (ft_strchr(arr[x], ',') == arr[x])
				readpoint_check(0, rows, view);
			r = (ft_strchr(arr[x], ',') == NULL) ?
					get_point_wc(arr[x], x, z, view) :
					get_point(arr[x], x, z, view);
			readpoint_check(r, rows, view);
			x++;
		}
		z++;
		iter = iter->next;
	}
}
