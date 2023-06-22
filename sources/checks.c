/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakdik <yakdik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:50:06 by yakdik            #+#    #+#             */
/*   Updated: 2023/04/14 13:23:43 by yakdik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	map_wall_check(t_main *main)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (row < main->map->y)
	{
		if (main->map->map[row][0] != '1' || main->map->map[row][main->map->x
			- 2] != '1')
			ft_error("Error\nMap checker: Left or Right is wrong.",
				main);
		row++;
	}
	while (col < (main->map->x - 1))
	{
		if (main->map->map[0][col] != '1' || main->map->map[main->map->y
			- 1][col] != '1')
			ft_error("Error\nMap checker: Top or Bottom is wrong.",
				main);
		col++;
	}
	return (1);
}

void	map_count_checker(t_main *main)
{
	if (main->ecount <= 0)
		ft_error("Error\nExit not found.", main);
	else if (main->ecount > 1)
		ft_error("Error\nThere are multiple exits.", main);
	else if (main->ccount <= 0)
		ft_error("Error\nCollectible not found.", main);
	else if (main->pcount <= 0)
		ft_error("Error\nPlayer not found.", main);
	else if (main->pcount > 1)
		ft_error("Error\nThere are multiple player.", main);
}

void	map_checker(t_main *main)
{
	int	i;
	int	j;

	i = 0;
	while (i < (main->map->y))
	{
		j = 0;
		while (j < (main->map->x))
		{
			if (main->map->map[i][j] == 'P')
			{
				main->pcount++;
				main->player_x = j;
				main->player_y = i;
			}
			map_cem_checker(&main, i, j);
			j++;
		}
		i++;
	}
	map_count_checker(main);
	map_wall_check(main);
}
