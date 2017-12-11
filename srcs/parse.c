/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:04:00 by abutok            #+#    #+#             */
/*   Updated: 2017/12/06 18:55:31 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"


void			arr2d_del(void ***arr)
{
	int i;

	i = -1;
	while (*arr[++i] != NULL)
		free(*arr[i]);
	free(*arr);
	*arr = NULL;
}

static void 	get_point_line(char ***points, t_point *row, int *rown)
{
	int		x;
	char	**val;

	x = -1;
	while (*points[++x] != NULL)
	{

		val = ft_strsplit(*points[x], ',');
		if (val == NULL || (val[1] != NULL && val[2] != NULL)
				|| !checkz(val[0]) || !checkcolorhex(val[1]))
		{
			arr2d_del((void*)(&points));
			arr2d_del((void*)(&val));
			perror(val == NULL ? "Point value split error" :
					"Invalid input");
		}
	}

	(*rown)++;
}

static void		parr_edel(t_point ***arr)
{
	arr2d_del(arr);
	perror("point array creation error");
	exit(-1);
}

static void		parr_row_add(t_point ***arr)
{
	t_point **new_arr;
	int		i;

	if (*arr == NULL)
	{
		errno = 0;
		if ((*arr = (t_point **) malloc(sizeof(t_point *) * 2)) == NULL)
		{
			perror("point array creation error");
			exit(-1);
		}
		ft_bzero(*arr, sizeof(t_point*) * 2);
		return ;
	}
	i = 0;
	while (*arr[i] != NULL)
		i++;
	if((new_arr = (t_point**)malloc(sizeof(t_point*) * (i + 2))) == NULL)
		parr_edel(&arr);
	ft_memcpy(new_arr, *arr, sizeof(t_point) * (i + 1));
	free(*arr);
	*arr = new_arr;
	*arr[i + 2] = NULL;
	return ;
}

t_point			**get_map(int fd, int *width, int *depth)
{
	char	*str;
	char	**str_splited;
	t_point	**result;
	int		i;

	i = 0;
	result = NULL;
	while (get_next_line(fd, &str))
	{
		if ((str_splited = ft_strsplit(str, ' ')) == NULL)
		{
			ft_strdel(&str);
			perror("ft_strsplit error");
			exit(-1);
		}
		ft_strdel(&str);
		if (*str_splited != NULL)
		{
			parr_row_add(&result);
			get_point_line(&str_splited, result[i], &i);
		}
	}
	return (result);
}
