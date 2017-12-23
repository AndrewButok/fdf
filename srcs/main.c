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


t_point start, start1, end;

t_view	*view_init()
{
	t_view *view;

	view = (t_view*)malloc(sizeof(t_view));
	view->mlx = mlx_init();
	view->win = mlx_new_window(view->mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
	view->mem = NULL;
	view->x = WIN_WIDTH;
	view->y = WIN_HEIGHT;

	start.x = 1200;
	start.y = 600;
	start.z = 200;
	end.x = 1200;
	end.y = 800;
	end.z = 200;
	start1.x = 1100;
	start1.y = 500;
	start1.z = 400;
	start.color.color = 0xff0000;
	start1.color.color = 0xff0000;
	end.color.color = 0x0000ff;
	return (view);
}

int 	exit_x(void *param)
{
	param = NULL;
	exit(1);
}

int 	button_draw(int kkode, t_view *view)
{
	view->img = mlx_new_image(view->mlx, WIN_WIDTH, WIN_HEIGHT);
	view->scene = mlx_get_data_addr(view->img, &view->bits_per_pixel,
			&view->size_line, &view->endian);
	if (kkode == 13)
	{
		rotate_x(&start, &end, 0.017*5);
		rotate_x(&start1, &end, 0.017*5);
	}
	if (kkode == 1)
	{
		rotate_x(&start, &end, -0.017*5);
		rotate_x(&start1, &end, -0.017*5);
	}
	if (kkode == 0)
	{
		rotate_y(&start, &end, -0.017*5);
		rotate_y(&start1, &end, -0.017*5);
	}
	if (kkode == 2)
	{
		rotate_y(&start, &end, 0.017*5);
		rotate_y(&start1, &end, 0.017*5);
	}
	if (kkode == 12)
	{
		rotate_z(&start, &end, -0.017*5);
		rotate_z(&start1, &end, -0.017*5);
	}
	if (kkode == 14)
	{
		rotate_z(&start, &end, 0.017*5);
		rotate_z(&start1, &end, 0.017*5);
	}
	t_line *line = get_line(&start, &end, view);
	t_line *line1 = get_line(&start1, &end, view);
	draw_line_antialias(line, view);
	draw_line_antialias(line1, view);
	free_line(&line, view);
	free_line(&line1, view);
	mlx_put_image_to_window(view->mlx, view->win, view->img, 0, 0);
	mlx_destroy_image(view->mlx, view->img);
	return (1);
}

int		main(int argc, char **argv)
{
	int		map_fd;
	t_view	*view;

	if (argc < 2)
	{
		ft_putendl("usage: fdf map_file [args]");
		return (0);
	}
	view = view_init();
	map_fd = open(argv[1], O_RDONLY);
	mlx_hook(view->win, 2, 5, &button_draw, view);
	mlx_hook(view->win, 17, 1L<<17, &exit_x, NULL);
	mlx_loop(view->mlx);
	return (0);
}
