/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 23:04:07 by abutok            #+#    #+#             */
/*   Updated: 2017/12/06 18:03:57 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include "fdf.h"
#define WIN_HEIGHT 800
#define WIN_WIDTH 600

int exit_x(void *param)
{
	param = NULL;
	exit(1);
	return (0);
}

int mouse_draw(int x, int y)
{
	t_point start, end;
	start.x = 400;
	start.y = 300;
	end.x = x;
	end.y = y;
	mlx_clear_window(g_mlx, g_win);
	start.color.color = 0xff0000;
	end.color.color = 0x0000ff;
	draw_line_antialias(&start, &end);
}

int	main(int argc, char **argv)
{
	int		map_fd;
	t_point	**map;

	if (argc < 2)
	{
		ft_putendl("usage: fdf map_file [args]");
		return (0);
	}
	map_fd = open(argv[1], O_RDONLY);

	g_mlx = mlx_init();
	g_win = mlx_new_window(g_mlx, WIN_HEIGHT, WIN_WIDTH, "fdf");
	mlx_hook(g_win, 6, 0, &mouse_draw, NULL);
	mlx_hook(g_win, 17, 1L<<17, &exit_x, NULL);
	mlx_loop(g_mlx);
}
