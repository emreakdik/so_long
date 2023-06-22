/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakdik <yakdik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:50:22 by yakdik            #+#    #+#             */
/*   Updated: 2023/04/13 15:50:23 by yakdik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_up(t_main *main)
{
	main->player_y--;
	main->mcount++;
	ft_putstr_fd("\033[1;42m\rMove:", 1);
	ft_putnbr_fd(main->mcount, 1);
	if (main->map->map[main->player_y][main->player_x] == 'C')
	{
		main->map->map[main->player_y][main->player_x] = '0';
		main->flag = 1;
		main->ccount--;
	}
}

void	ft_left(t_main *main)
{
	main->player_x--;
	main->mcount++;
	ft_putstr_fd("\033[1;42m\rMove:", 1);
	ft_putnbr_fd(main->mcount, 1);
	if (main->map->map[main->player_y][main->player_x] == 'C')
	{
		main->map->map[main->player_y][main->player_x] = '0';
		main->flag = 1;
		main->ccount--;
	}
}

void	ft_down(t_main *main)
{
	main->player_y++;
	main->mcount++;
	ft_putstr_fd("\033[1;42m\rMove:", 1);
	ft_putnbr_fd(main->mcount, 1);
	if (main->map->map[main->player_y][main->player_x] == 'C')
	{
		main->map->map[main->player_y][main->player_x] = '0';
		main->flag = 1;
		main->ccount--;
	}
}

void	ft_right(t_main *main)
{
	main->player_x++;
	main->mcount++;
	ft_putstr_fd("\033[1;42m\rMove:", 1);
	ft_putnbr_fd(main->mcount, 1);
	if (main->map->map[main->player_y][main->player_x] == 'C')
	{
		main->map->map[main->player_y][main->player_x] = '0';
		main->flag = 1;
		main->ccount--;
	}
}

int	key_hook(int keycode, t_main *main)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(main->mlx, main->win);
		exit(0);
	}
	else if (keycode == W && main->map->map[main->player_y
			- 1][main->player_x] != '1')
		ft_up(main);
	else if (keycode == A && main->map->map[main->player_y][main->player_x
		- 1] != '1')
		ft_left(main);
	else if (keycode == S && main->map->map[main->player_y
			+ 1][main->player_x] != '1')
		ft_down(main);
	else if (keycode == D && main->map->map[main->player_y][main->player_x
		+ 1] != '1')
		ft_right(main);
	return (0);
}
