/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 23:04:07 by abutok            #+#    #+#             */
/*   Updated: 2018/02/23 15:20:58 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_view	*view_init(int fd)
{
	t_view *view;

	view = (t_view*)malloc(sizeof(t_view));
	view->mlx = mlx_init();
	view->win = mlx_new_window(view->mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
	view->mem = NULL;
	view->x = WIN_WIDTH;
	view->y = WIN_HEIGHT;
	view->ospeed = 2;
	view->zoom = 1.0;
	(view->draw_line) = &draw_line;
	view->points = NULL;
	parse_points(fd, view);
	merge_sort(&view->points, view->plen);
	select_rp(view);
	return (view);
}

int 	exit_x(t_view *view)
{
	memclear(&view->mem);
	mlx_destroy_window(view->mlx, view->win);
	free(view->mlx);
	free(view);
	exit(1);
}

int 	button_action(int key, t_view *view)
{
	view->img = mlx_new_image(view->mlx, WIN_WIDTH, WIN_HEIGHT);
	view->scene = mlx_get_data_addr(view->img, &view->bits_per_pixel,
			&view->size_line, &view->endian);
	
	if (key == G_KEY)
		view->draw_line = view->draw_line == &draw_line ?
				&draw_line_antialias : &draw_line;
	if (key == ESC_KEY)
		exit_x(view);
	button_rotate(key, view);
	merge_sort(&view->points, view->plen);
	draw_fdf(view);
	mlx_put_image_to_window(view->mlx, view->win, view->img, 0, 0);
	mlx_destroy_image(view->mlx, view->img);
	mlx_string_put(view->mlx, view->win, 20, 20, 0xffffff, ft_strjoin("rotation speed:", ft_itoa(view->ospeed)));
	return (1);
}

int		main(int argc, char **argv)
{
	int		map_fd;
	t_view	*view;

	if (argc != 2)
	{
		ft_putendl("usage: fdf map_file [args]");
		return (0);
	}
	errno = 0;
	map_fd = open(argv[1], O_RDONLY);
	if (errno)
	{
		perror("File opening error");
		exit(-1);
	}
	view = view_init(map_fd);
	mlx_hook(view->win, 2, 5, &button_action, view);
	mlx_hook(view->win, 17, 1L<<17, &exit_x, view);
	mlx_loop(view->mlx);
	return (0);
}
