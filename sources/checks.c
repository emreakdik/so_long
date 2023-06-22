/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakdik <yakdik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:50:06 by yakdik            #+#    #+#             */
/*   Updated: 2023/04/13 15:50:27 by yakdik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ber_check(char *map_path)
{
	int	i;

	i = 0;
	while (map_path[i])
		i++;
	if (!(map_path[i - 1] == 'r' && map_path[i - 2] == 'e' && map_path[i
			- 3] == 'b' && map_path[i - 4] == '.'))
	{
		ft_error("\033[0;91mWrong file extension. It should be .ber extension.\033[0;39m",
				NULL);
		exit(0);
	}
}

void	check_parameters(int ac, char **av, t_main *game)
{
	int	map_parameter_len;

	if (ac > 2)
		ft_error("Too many arguments (It should be only two).", game);
	if (ac < 2)
		ft_error("The Map file is missing.", game);
	map_parameter_len = ft_strlen(av[1]);
	if (!ft_strnstr(&av[1][map_parameter_len - 4], ".ber", 4))
		ft_error("Map file extention is wrong (It should be .ber).", game);
}

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
		{
			ft_error("\033[0;91mError\nMap checker: Left or Right is wrong.\033[0;39m",
					main);
			return (0);
		}
		row++;
	}
	while (col < (main->map->x - 1))
	{
		if (main->map->map[0][col] != '1' || main->map->map[main->map->y
			- 1][col] != '1')
		{
			ft_error("\033[0;91mError\nMap checker: Top or Bottom is wrong.\033[0;39m",
					main);
			return (0);
		}
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

int	map_checker(t_main *main)
{
	int i;
	int j;

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
			if (main->map->map[i][j] == 'C')
				main->ccount++;
			if (main->map->map[i][j] == 'E')
				main->ecount++;
			if (main->map->map[i][j] == 'M')
				main->mcount++;
			j++;
		}
		i++;
	}
	map_count_checker(main);
	map_wall_check(main);
	return (0);
}