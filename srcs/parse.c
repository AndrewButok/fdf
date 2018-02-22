/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 09:16:00 by abutok            #+#    #+#             */
/*   Updated: 2018/02/20 09:16:00 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_rowdel(void *str, size_t size)
{
	free(str);
	size = 0;
}

void	get_rows(int fd, t_list **rows, t_view *view)
{
	char	*str;
	t_list	*b;
	int		gnlr;

	while ((gnlr = get_next_line(fd, &str)) > 0)
	{
		if (*rows == NULL)
		{
			*rows = ft_lstnew(str, ft_strlen(str) + 1);
			memreg(&view->mem, *rows);
		}
		else
		{
			b = ft_lstnew(str, ft_strlen(str) + 1);
			memreg(&view->mem, b);
			ft_lstadd(rows, b);
		}
	}
	if (gnlr == -1)
	{
		perror("Map reading error.");
		ft_lstdel(rows, &ft_rowdel);
		exit_x(view);
	}
}

void	ft_splitedrowdel(void *str, size_t size)
{
	char	**strs;
	size_t	i;

	strs = (char**)str;
	i = 0;
	while (i < size)
		free(strs[i++]);
	free(strs);
}

void	get_splited_rows(t_list **rows, t_view *view)
{
	size_t	len;
	char	**splitrow;
	t_list	*it;

	it = *rows;
	while (it)
	{
		splitrow = ft_strsplit(it->content, ' ');
		free(it->content);
		it->content = splitrow;
		len = 0;
		if (splitrow != NULL)
			while (splitrow[len])
				len++;
		it->content_size = len;
		it = it->next;
	}
	check_splited_rows(rows, view);
}

void	parse_points(int fd, t_view *view)
{
	t_list *rows;
	t_list *iter;
	size_t rowlen;

	rows = NULL;
	get_rows(fd, &rows, view);
	get_splited_rows(&rows, view);
	if (rows != NULL)
	{
		rowlen = check_size(&rows, view);
		get_points(&rows, view);
		find_neighbours(view->points, rowlen);
		rows = view->points;
		rowlen = 0;
		iter = rows;
		//TODO ROWS CLEAN
		while (rows)
		{
			rowlen++;
			rows = rows->next;
		}
		view->plen = rowlen;
	}
}
