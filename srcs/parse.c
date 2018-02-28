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

void	get_rows(int fd, t_list **rows, t_view *view)
{
	char	*str;
	t_list	*b;
	int		gnlr;

	while ((gnlr = get_next_line(fd, &str)) > 0)
	{
		if (*rows == NULL)
			*rows = ft_lstnew(str, ft_strlen(str) + 1);
		else
		{
			b = ft_lstnew(str, ft_strlen(str) + 1);
			ft_lstadd(rows, b);
		}
		ft_strdel(&str);
	}
	ft_strdel(&str);
	if (gnlr == -1)
	{
		perror("Map reading error.");
		ft_lstdelc(rows, &rm_point);
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
		ft_strdel(&strs[i++]);
	free(strs);
}

void	get_splited_rows(t_list **rows, t_view *view)
{
	size_t	len;
	char	**splitrow;
	char	*str;
	t_list	*it;

	it = *rows;
	while (it)
	{
		str = (char*)it->content;
		splitrow = ft_strsplit(str, ' ');
		ft_strdel(&str);
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
	size_t lstlen;

	rows = NULL;
	get_rows(fd, &rows, view);
	get_splited_rows(&rows, view);
	if (rows != NULL)
	{
		view->rowlen = check_size(&rows, view);
		get_points(&rows, view);
		ft_lstdelc(&rows, &ft_splitedrowdel);
		lstlen = 0;
		iter = view->points;
		while (iter)
		{
			lstlen++;
			iter = iter->next;
		}
		view->plen = lstlen;
	}
}
