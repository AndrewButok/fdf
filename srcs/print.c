/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutok <abutok@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 09:18:00 by abutok            #+#    #+#             */
/*   Updated: 2017/12/05 09:18:00 by abutok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_speed(t_view *view)
{
	char *str;
	char *d;

	d = ft_itoa(view->ospeed);
	str = ft_strjoin("Rotation and moving speed: ", d);
	ft_strdel(&d);
	mlx_string_put(view->mlx, view->win, 20, 20, 0xffffff, str);
	ft_strdel(&str);
}

void	print_zoom(t_view *view)
{
	char *str;
	char *d;

	if (view->zoom >= -1)
	{
		d = ft_itoa(abs(view->zoom));
		str = ft_strjoin("Zoom: x ", d);
	}
	else
	{
		d = ft_itoa(abs(view->zoom));
		str = ft_strjoin("Zoom: x 1/", d);
	}
	ft_strdel(&d);
	mlx_string_put(view->mlx, view->win, 20, 20, 0xffffff, str);
	ft_strdel(&str);
}

void	print_text(int key, t_view *view)
{
	if (key == F1_KEY)
	{
		mlx_string_put(view->mlx, view->win, 20, 20, 0xffffff,
				"W A S D Q E keys for map rotation");
		mlx_string_put(view->mlx, view->win, 20, 40, 0xffffff,
				"H J U K keys to move map");
		mlx_string_put(view->mlx, view->win, 20, 60, 0xffffff,
				"+ - keys to zoom map");
		mlx_string_put(view->mlx, view->win, 20, 80, 0xffffff,
				"Up and down arrows keys to change rotation and moving speed");
	}
	if (key == AU_KEY || key == AD_KEY)
		print_speed(view);
	if (key == PLUS_KEY || key == MINUS_KEY)
		print_zoom(view);
}
