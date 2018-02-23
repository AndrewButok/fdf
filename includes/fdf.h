/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:19:00 by abutok            #+#    #+#             */
/*   Updated: 2018/02/23 15:28:38 by abutok           ###   ########.fr       */
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
# define Q_KEY 12
# define W_KEY 13
# define E_KEY 14
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define AU_KEY 126
# define AD_KEY 125
# define G_KEY 5
# define ESC_KEY 53

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
	int				x;
	int				y;
	int				z;
	t_color			color;
	struct s_point	*right;
	struct s_point	*bottom;
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
	t_point	*rp;
	size_t	plen;
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
int						exit_x(t_view *view);
void					group_rotate(t_list *ps, t_point *p0,
	double angle, int axis);
void					zoom(t_list *ps, double x);
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
int						ft_hexatoi(char *str);
void					check_splited_rows(t_list **rows, t_view *view);
void					readpoint_check(int r, t_list **rows, t_view *view);
void					find_neighbours(t_list *points, size_t rowsize);
int						check_num(char *str);
void					merge_sort(t_list **list, size_t len);
void					select_rp(t_view *view);
void					draw_fdf(t_view *view);
void					button_rotate(int key, t_view *view);
void					rp_check(t_view *view);

#endif
