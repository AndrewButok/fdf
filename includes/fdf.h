/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:19:00 by abutok            #+#    #+#             */
/*   Updated: 2017/12/11 12:57:16 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <math.h>
# include <stdbool.h>
# include <fcntl.h>
# include "libft.h"
# include "mlx_color.h"
# include "get_next_line.h"

void	*g_mlx;
void	*g_win;

typedef struct	s_point
{
	int		x;
	int		y;
	int 	z;
	t_color	color;
}				t_point;

int				linear_gradient(t_point *start, t_point *end, bool f, int i);
void			draw_line(t_point *start, t_point *end);
void			draw_line_antialias(t_point *start, t_point *end);
t_point			**get_map(int fd, int *width, int *depth);
bool			checkz(char *str);
bool			checkcolorhex(char *str);

#endif
