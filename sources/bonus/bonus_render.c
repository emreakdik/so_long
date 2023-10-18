/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakdik <yakdik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:50:01 by yakdik            #+#    #+#             */
/*   Updated: 2023/10/18 20:52:26 by yakdik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

static void	bonus_render_ode(t_main *main, int i, int j)
{
	if (main->map->map[i][j] == 'D')
	{
		mlx_put_image_to_window(main->mlx, main->win, main->sprite->tile, j
			* PIXEL, i * PIXEL);
		mlx_put_image_to_window(main->mlx, main->win,
			main->sprite->enemy[main->i], j * PIXEL, i * PIXEL);
	}
	else if (main->map->map[i][j] == 'O')
	{
		mlx_put_image_to_window(main->mlx, main->win, main->sprite->tile, j
			* PIXEL, i * PIXEL);
		mlx_put_image_to_window(main->mlx, main->win, main->sprite->open_chest,
			j * PIXEL, i * PIXEL);
	}
	else if (main->map->map[i][j] == 'E')
	{
		mlx_put_image_to_window(main->mlx, main->win, main->sprite->tile, j
			* PIXEL, i * PIXEL);
		mlx_put_image_to_window(main->mlx, main->win, main->sprite->exit, j
			* PIXEL, i * PIXEL);
	}
}

static void	bonus_render_player3(t_main *main)
{
	if (main->sprite->player_direction == 'R')
		mlx_put_image_to_window(main->mlx, main->win,
			main->sprite->player_right[main->i], main->player_x * PIXEL,
			main->player_y * PIXEL);
	else if (main->sprite->player_direction == 'L')
		mlx_put_image_to_window(main->mlx, main->win,
			main->sprite->player_left[main->i], main->player_x * PIXEL,
			main->player_y * PIXEL);
	else if (main->sprite->player_direction == 'U')
		mlx_put_image_to_window(main->mlx, main->win,
			main->sprite->player_up[main->i], main->player_x * PIXEL,
			main->player_y * PIXEL);
	else if (main->sprite->player_direction == 'D')
		mlx_put_image_to_window(main->mlx, main->win,
			main->sprite->player_down[main->i], main->player_x * PIXEL,
			main->player_y * PIXEL);
	else
		mlx_put_image_to_window(main->mlx, main->win,
			main->sprite->player_down[main->i], main->player_x * PIXEL,
			main->player_y * PIXEL);
}

static void	bonus_render_player2(t_main *main, int i)
{
	int	j;

	j = 0;
	while (j < main->map->x)
	{
		if (main->map->map[i][j] == '1')
			mlx_put_image_to_window(main->mlx, main->win,
				main->sprite->bonus_wall[main->j], j * PIXEL, i * PIXEL);
		else if (main->map->map[i][j] == '0' || main->map->map[i][j] == 'P')
			mlx_put_image_to_window(main->mlx, main->win, main->sprite->tile, j
				* PIXEL, i * PIXEL);
		else if (main->map->map[i][j] == 'C')
			mlx_put_image_to_window(main->mlx, main->win, main->sprite->coin, j
				* PIXEL, i * PIXEL);
		else if (main->map->map[i][j] == 'O' || main->map->map[i][j] == 'D'
			|| main->map->map[i][j] == 'E')
			bonus_render_ode(main, i, j);
		j++;
	}
}

static int	bonus_render_player(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->map->y)
	{
		bonus_render_player2(main, i);
		i++;
	}
	bonus_render_player3(main);
	return (0);
}

int	bonus_render(t_main *main)
{
	main->loop_count++;
	animation_timer(main);
	animation_timer_wall(main);
	bonus_render_player(main);
	print_count(main);
	if (main->c_count == 0
		&& main->map->map[main->player_y][main->player_x] == 'E')
		bonus_key_hook(ESC, main);
	return (0);
}
