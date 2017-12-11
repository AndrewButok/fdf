/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 23:04:07 by abutok            #+#    #+#             */
/*   Updated: 2017/12/05 00:08:34 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include "fdf.h"
#define WIN_WIDTH 800
#define WIN_HEIGHT 600

t_view	*view_init()
{
	t_view *view;

	view = (t_view*)malloc(sizeof(t_view));
	view->mlx = mlx_init();
	view->win = mlx_new_window(view->mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
	view->x = WIN_WIDTH;
	view->y = WIN_HEIGHT;
	return (view);
}

int 	exit_x(void *param)
{
	param = NULL;
	exit(1);
	return (0);
}

int 	mouse_draw(int x, int y, t_view *view)
{
	view->img = mlx_new_image(view->mlx, WIN_WIDTH, WIN_HEIGHT);
	view->scene = mlx_get_data_addr(view->img, &view->bits_per_pixel,
			&view->size_line, &view->endian);
	t_point start, end;
	start.x = 400;
	start.y = 300;
	end.x = x;
	end.y = y;
	start.color.color = 0xff0000;
	end.color.color = 0x0000ff;
	t_line *line = get_line(&start, &end);
	draw_line_antialias(line, view);
	free_line(&line);
	mlx_put_image_to_window(view->mlx, view->win, view->img, 0, 0);
	mlx_destroy_image(view->mlx, view->img);
}

int		main(int argc, char **argv)
{
	int		map_fd;
	t_point	**map;
	t_view	*view;

	if (argc < 2)
	{
		ft_putendl("usage: fdf map_file [args]");
		return (0);
	}
	view = view_init();
	map_fd = open(argv[1], O_RDONLY);
	mlx_hook(view->win, 6, 0, &mouse_draw, view);
	mlx_hook(view->win, 17, 1L<<17, &exit_x, NULL);
	mlx_loop(view->mlx);
}
