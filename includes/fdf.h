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
# include "get_next_line.h"
# define WIN_WIDTH 800
# define WIN_HEIGHT 600

typedef union			u_color
{
	int		color;
	struct
	{
		unsigned char	blue;
		unsigned char	green;
		unsigned char	red;
		unsigned char	alpha;
	}		spectrum;
}						t_color;

typedef struct			s_point
{
	int		x;
	int		y;
	int		z;
	t_color	color;
	t_point *right;
	t_point *bottom;
}						t_point;

typedef struct			s_line
{
	t_point *start;
	t_point	*end;
}						t_line;

typedef struct			s_mlist
{
	struct s_mlist	*next;
	void			*content;
}						t_mlist;

typedef struct			s_view
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*scene;
	t_list	*points;
	t_mlist	*mem;
	int		bits_per_pixel;
	int		endian;
	int		x;
	int		y;
	int		size_line;
	int		ospeed;
	double	zoom;
	void	(*draw_line)(t_line*, struct s_view*);
}						t_view;

void					memreg(t_mlist **mem_list, void *content);
void					memregdel(t_mlist **mem_list, void *memtodel);
void					memclear(t_mlist **mem_list);
int 					exit_x(t_view *view);
void					group_rotate(t_point **ps, t_point *p0, double angle, int axis);
void					zoom(t_point **ps, double x);
int						linear_gradient(t_point *start, t_point *end,
		bool f, int i);
void					draw_line(t_line *line, t_view *view);
void					draw_line_antialias(t_line *line,
		t_view *view);
void					img_pixel_put(t_view *view,
		int x, int y, t_color color);
t_line					*get_line(t_point *start, t_point *end, t_view *view);
void					free_line(t_line **line, t_view *view);
t_point					**get_map(int fd, int *width, int *depth);
bool					is_null(void *link);
void					line_check(t_view *view);
void					parse_points(int fd, t_view *view);
void					ft_splitedrowdel(void *str, size_t size);
size_t					check_size(t_list **rows, t_view *view);
void					get_points(t_list **rows, t_view *view);
int 					ft_hexatoi(char *str);
void					check_splited_rows(t_list **rows, t_view *view);
void					readpoint_check(int r, t_list **rows, t_view *view);
void					find_neighbours(t_list *points, size_t rowsize);

#endif
