/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakdik <yakdik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:50:29 by yakdik            #+#    #+#             */
/*   Updated: 2023/04/13 15:50:30 by yakdik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	bonus_ft_up(t_main *main)
{
	main->player_y--;
	main->mcount++;
	ft_putstr_fd("\033[1;42m\rMove:", 1);
	ft_putnbr_fd(main->mcount, 1);
	if (main->map->map[main->player_y][main->player_x] == 'C')
	{
		main->map->map[main->player_y][main->player_x] = 'O';
		main->ccount--;
	}
	if (main->map->map[main->player_y][main->player_x] == 'D')
	{
		ft_error("\nTHE COW ATE YOU!", main);
		mlx_destroy_window(main->mlx, main->win);
		exit(0);
	}
	main->sprite->player_direction = 'U';
}

void	bonus_ft_left(t_main *main)
{
	main->player_x--;
	main->mcount++;
	ft_putstr_fd("\033[1;42m\rMove:", 1);
	ft_putnbr_fd(main->mcount, 1);
	if (main->map->map[main->player_y][main->player_x] == 'C')
	{
		main->map->map[main->player_y][main->player_x] = 'O';
		main->ccount--;
	}
	if (main->map->map[main->player_y][main->player_x] == 'D')
	{
		ft_error("\nTHE COW ATE YOU!", main);
		mlx_destroy_window(main->mlx, main->win);
		exit(0);
	}
	main->sprite->player_direction = 'L';
}

void	bonus_ft_down(t_main *main)
{
	main->player_y++;
	main->mcount++;
	ft_putstr_fd("\033[1;42m\rMove:", 1);
	ft_putnbr_fd(main->mcount, 1);
	if (main->map->map[main->player_y][main->player_x] == 'C')
	{
		main->map->map[main->player_y][main->player_x] = 'O';
		main->ccount--;
	}
	if (main->map->map[main->player_y][main->player_x] == 'D')
	{
		ft_error("\nTHE COW ATE YOU!", main);
		mlx_destroy_window(main->mlx, main->win);
		exit(0);
	}
	main->sprite->player_direction = 'D';
}

void	bonus_ft_right(t_main *main)
{
	main->player_x++;
	main->mcount++;
	ft_putstr_fd("\033[1;42m\rMove:", 1);
	ft_putnbr_fd(main->mcount, 1);
	if (main->map->map[main->player_y][main->player_x] == 'C')
	{
		main->map->map[main->player_y][main->player_x] = 'O';
		main->ccount--;
	}
	if (main->map->map[main->player_y][main->player_x] == 'D')
	{
		ft_error("\nTHE COW ATE YOU!", main);
		mlx_destroy_window(main->mlx, main->win);
		exit(0);
	}
	main->sprite->player_direction = 'R';
}

int	bonus_key_hook(int keycode, t_main *main)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(main->mlx, main->win);
		exit(0);
	}
	else if (keycode == W && main->map->map[main->player_y
			- 1][main->player_x] != '1' && main->map->map[main->player_y
			- 1][main->player_x] != 'K')
		bonus_ft_up(main);
	else if (keycode == A && main->map->map[main->player_y][main->player_x
		- 1] != '1' && main->map->map[main->player_y][main->player_x
			- 1] != 'K')
		bonus_ft_left(main);
	else if (keycode == S && main->map->map[main->player_y
			+ 1][main->player_x] != '1' && main->map->map[main->player_y
			+ 1][main->player_x] != 'K')
		bonus_ft_down(main);
	else if (keycode == D && main->map->map[main->player_y][main->player_x
		+ 1] != '1' && main->map->map[main->player_y][main->player_x
			+ 1] != 'K')
		bonus_ft_right(main);
	return (0);
}
