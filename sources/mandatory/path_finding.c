/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakdik <yakdik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:50:20 by yakdik            #+#    #+#             */
/*   Updated: 2023/10/18 21:48:00 by yakdik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include <stdlib.h>

static void	path_finding(int **v_map, t_main *main, int y, int x)
{
	if (main->map->map[y][x] == 'E' || main->map->map[y][x] == 'C')
		main->read_count++;
	if (main->map->map[y - 1][x] != '1' && v_map[y - 1][x] < 1)
	{
		v_map[y - 1][x] = v_map[y][x] + 1;
		path_finding(v_map, main, y - 1, x);
	}
	if (main->map->map[y][x + 1] != '1' && v_map[y][x + 1] < 1)
	{
		v_map[y][x + 1] = v_map[y][x] + 1;
		path_finding(v_map, main, y, x + 1);
	}
	if (main->map->map[y + 1][x] != '1' && v_map[y + 1][x] < 1)
	{
		v_map[y + 1][x] = v_map[y][x] + 1;
		path_finding(v_map, main, y + 1, x);
	}
	if (main->map->map[y][x - 1] != '1' && v_map[y][x - 1] < 1)
	{
		v_map[y][x - 1] = v_map[y][x] + 1;
		path_finding(v_map, main, y, x - 1);
	}
}

int	virtual_map(t_main *main, int y, int x)
{
	int	**v_map;

	v_map = (int **)malloc(sizeof(int *) * main->map->y);
	if (!v_map)
		return (1);
	while (y < main->map->y)
	{
		v_map[y] = (int *)malloc(sizeof(int) * main->map->x);
		if (!v_map[y])
			return (free(v_map), 1);
		x = 0;
		while (x < main->map->x)
		{
			v_map[y][x] = 0;
			x++;
		}
		y++;
	}
	v_map[main->player_y][main->player_x] = 1;
	path_finding(v_map, main, main->player_y, main->player_x);
	if (main->read_count != main->c_count + 1)
		ft_error("Error\nCollectables are not accessible!", main);
	virtual_map_free(v_map, main);
	return (0);
}
