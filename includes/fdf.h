/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:19:00 by abutok            #+#    #+#             */
/*   Updated: 2017/12/05 00:02:05 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <math.h>
# include <errno.h>
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include "libft.h"
# include "mlx_color.h"
# include "get_next_line.h"

typedef struct	s_view
{
	void 	*mlx;
	void 	*win;
	void 	*img;
	char 	*scene;
	int 	bits_per_pixel;
	int 	endian;
	int 	x;
	int 	y;
	int 	size_line;
}				t_view;

typedef struct	s_point
{
	int		x;
	int		y;
	int 	z;
	t_color	color;
}				t_point;

typedef struct	s_line
{
	t_point *start;
	t_point	*end;
}				t_line;

typedef struct	s_mlist
{
	struct s_mlist	*next;
	void			*content;
}				t_mlist;

void			memreg(t_mlist **mem_list, void *content);
void			memdel(t_mlist **mem_list, t_mlist *memtodel);
void			memclear(t_mlist **mem_list);
int				linear_gradient(t_point *start, t_point *end, bool f, int i);
void			draw_line(t_line *line, t_view *view);
void			draw_line_antialias(t_line *line, t_view *view);
void			img_pixel_put(t_view *view, int x, int y, t_color color);
t_line			*get_line(t_point *start, t_point *end);
void			free_line(t_line **line);
t_point			**get_map(int fd, int *width, int *depth);
bool			is_null(void *link);

#endif
