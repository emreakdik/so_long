/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakdik <yakdik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:50:31 by yakdik            #+#    #+#             */
/*   Updated: 2023/10/18 20:52:21 by yakdik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

static int	bonus_convert_player(t_main *main)
{
	int	x;
	int	y;

	main->sprite->player_right[0] = mlx_xpm_file_to_image(main->mlx,
			"./images/player_right1.xpm", &x, &y);
	main->sprite->player_right[1] = mlx_xpm_file_to_image(main->mlx,
			"./images/player_right2.xpm", &x, &y);
	main->sprite->player_left[0] = mlx_xpm_file_to_image(main->mlx,
			"./images/player_left1.xpm", &x, &y);
	main->sprite->player_left[1] = mlx_xpm_file_to_image(main->mlx,
			"./images/player_left2.xpm", &x, &y);
	main->sprite->player_down[0] = mlx_xpm_file_to_image(main->mlx,
			"./images/player_down1.xpm", &x, &y);
	main->sprite->player_down[1] = mlx_xpm_file_to_image(main->mlx,
			"./images/player_down2.xpm", &x, &y);
	main->sprite->player_up[0] = mlx_xpm_file_to_image(main->mlx,
			"./images/player_up1.xpm", &x, &y);
	main->sprite->player_up[1] = mlx_xpm_file_to_image(main->mlx,
			"./images/player_up2.xpm", &x, &y);
	if (!main->sprite->player_right[0] || !main->sprite->player_right[1]
		|| !main->sprite->player_left[0] || !main->sprite->player_left[1]
		|| !main->sprite->player_down[0] || !main->sprite->player_down[1]
		|| !main->sprite->player_up[0] || !main->sprite->player_up[1])
		return (1);
	return (0);
}

static int	bonus_convert_sprite(t_main *main)
{
	int	x;
	int	y;

	main->sprite->bonus_wall[0] = mlx_xpm_file_to_image(main->mlx,
			"./images/wall1.xpm", &x, &y);
	main->sprite->bonus_wall[1] = mlx_xpm_file_to_image(main->mlx,
			"./images/wall2.xpm", &x, &y);
	main->sprite->coin = mlx_xpm_file_to_image(main->mlx,
			"./images/close_chest.xpm", &x, &y);
	main->sprite->tile = mlx_xpm_file_to_image(main->mlx,
			"./images/background.xpm", &x, &y);
	main->sprite->exit = mlx_xpm_file_to_image(main->mlx, "./images/exit.xpm",
			&x, &y);
	main->sprite->open_chest = mlx_xpm_file_to_image(main->mlx,
			"./images/open_chest.xpm", &x, &y);
	main->sprite->fences = mlx_xpm_file_to_image(main->mlx,
			"./images/fences.xpm", &x, &y);
	if (!main->sprite->bonus_wall[0] || !main->sprite->bonus_wall[1]
		|| !main->sprite->coin || !main->sprite->tile || !main->sprite->exit
		|| !main->sprite->open_chest || !main->sprite->fences)
		return (1);
	return (0);
}

static int	bonus_draw_map3(t_main *main, int i, int j)
{
	if (main->map->map[i][j] == 'E')
		mlx_put_image_to_window(main->mlx, main->win, main->sprite->exit, j
			* PIXEL, i * PIXEL);
	else if (main->map->map[i][j] == 'C')
	{
		mlx_put_image_to_window(main->mlx, main->win, main->sprite->tile, j
			* PIXEL, i * PIXEL);
		mlx_put_image_to_window(main->mlx, main->win, main->sprite->coin, j
			* PIXEL, i * PIXEL);
	}
	else if (main->map->map[i][j] == 'K')
	{
		mlx_put_image_to_window(main->mlx, main->win, main->sprite->tile, j
			* PIXEL, i * PIXEL);
		mlx_put_image_to_window(main->mlx, main->win, main->sprite->fences, j
			* PIXEL, i * PIXEL);
	}
	else if (main->map->map[i][j] == 'D')
	{
		mlx_put_image_to_window(main->mlx, main->win, main->sprite->tile, j
			* PIXEL, i * PIXEL);
		mlx_put_image_to_window(main->mlx, main->win, main->sprite->enemy[0], j
			* PIXEL, i * PIXEL);
	}
	return (j);
}

static int	bonus_draw_map2(t_main *main, int i, int j)
{
	if (main->map->map[i][j] == '1')
		mlx_put_image_to_window(main->mlx, main->win,
			main->sprite->bonus_wall[main->j], j * PIXEL, i * PIXEL);
	else if (main->map->map[i][j] == '0')
		mlx_put_image_to_window(main->mlx, main->win, main->sprite->tile, j
			* PIXEL, i * PIXEL);
	else if (main->map->map[i][j] == 'P')
	{
		mlx_put_image_to_window(main->mlx, main->win,
			main->sprite->player_down[0], j * PIXEL, i * PIXEL);
		main->player_y = i;
		main->player_x = j;
	}
	else if (main->map->map[i][j] == 'C' || main->map->map[i][j] == 'E'
		|| main->map->map[i][j] == 'K' || main->map->map[i][j] == 'D')
		j = bonus_draw_map3(main, i, j);
	else
		bonus_map_control(main, i, j);
	j++;
	return (j);
}

int	bonus_draw_map(t_main *main)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (bonus_convert_sprite(main) || bonus_convert_player(main))
		return (1);
	if (bonus_convert_enemy(main))
		return (1);
	bonus_convert_null(main);
	while (i < (main->map->y))
	{
		while (j < (main->map->x - 1))
		{
			j = bonus_draw_map2(main, i, j);
		}
		i++;
		j = 0;
	}
	return (0);
}
