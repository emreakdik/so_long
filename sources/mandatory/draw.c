/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakdik <yakdik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:50:25 by yakdik            #+#    #+#             */
/*   Updated: 2023/10/18 20:51:54 by yakdik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	xpm_check(t_main *main)
{
	if (!main->sprite->wall || !main->sprite->player || !main->sprite->coin
		|| !main->sprite->tile || !main->sprite->exit
		|| !main->sprite->open_chest)
		return (1);
	return (0);
}

static int	convert(t_main *main)
{
	int	x;
	int	y;

	main->sprite->wall = mlx_xpm_file_to_image(main->mlx, "./images/wall1.xpm",
			&x, &y);
	main->sprite->player = mlx_xpm_file_to_image(main->mlx,
			"./images/player_down1.xpm", &x, &y);
	main->sprite->coin = mlx_xpm_file_to_image(main->mlx,
			"./images/close_chest.xpm", &x, &y);
	main->sprite->tile = mlx_xpm_file_to_image(main->mlx,
			"./images/background.xpm", &x, &y);
	main->sprite->exit = mlx_xpm_file_to_image(main->mlx, "./images/exit.xpm",
			&x, &y);
	main->sprite->open_chest = mlx_xpm_file_to_image(main->mlx,
			"./images/open_chest.xpm", &x, &y);
	if (xpm_check(main))
		return (1);
	return (0);
}

int	draw_map3(t_main *main, int i, int j)
{
	if (main->map->map[i][j] == 'E')
	{
		mlx_put_image_to_window(main->mlx, main->win, main->sprite->tile, j
			* PIXEL, i * PIXEL);
		mlx_put_image_to_window(main->mlx, main->win, main->sprite->exit, j
			* PIXEL, i * PIXEL);
	}
	else if (main->map->map[i][j] == 'C')
	{
		mlx_put_image_to_window(main->mlx, main->win, main->sprite->tile, j
			* PIXEL, i * PIXEL);
		mlx_put_image_to_window(main->mlx, main->win, main->sprite->coin, j
			* PIXEL, i * PIXEL);
	}
	return (j);
}

int	draw_map2(t_main *main, int i, int j)
{
	if (main->map->map[i][j] == '1')
		mlx_put_image_to_window(main->mlx, main->win, main->sprite->wall, j
			* PIXEL, i * PIXEL);
	else if (main->map->map[i][j] == '0')
		mlx_put_image_to_window(main->mlx, main->win, main->sprite->tile, j
			* PIXEL, i * PIXEL);
	else if (main->map->map[i][j] == 'P')
	{
		mlx_put_image_to_window(main->mlx, main->win, main->sprite->player, j
			* PIXEL, i * PIXEL);
		main->player_y = i;
		main->player_x = j;
	}
	else if (main->map->map[i][j] == 'C' || main->map->map[i][j] == 'E')
		j = draw_map3(main, i, j);
	else
		map_control(main, i, j);
	j++;
	return (j);
}

int	draw_map(t_main *main)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (convert(main))
		return (1);
	while (i < (main->map->y))
	{
		while (j < (main->map->x - 1))
		{
			j = draw_map2(main, i, j);
		}
		i++;
		j = 0;
	}
	return (0);
}
