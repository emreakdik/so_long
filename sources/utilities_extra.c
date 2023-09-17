/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_extra.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakdik <yakdik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:37:39 by yakdik            #+#    #+#             */
/*   Updated: 2023/04/19 14:37:40 by yakdik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	bonus_map_control(t_main *main, int i, int j)
{
	if (main->map->map[i][j] != 'P' || main->map->map[i][j] != '1'
		|| main->map->map[i][j] != 'C' || main->map->map[i][j] != 'E'
		|| main->map->map[i][j] != '0' || main->map->map[i][j] != 'K'
		|| main->map->map[i][j] != 'D')
	{
		ft_error("Error\nWrong character on map.", main);
	}
}

void	map_cem_checker(t_main **main, int i, int j)
{
	if ((*main)->map->map[i][j] == 'C')
		(*main)->ccount++;
	if ((*main)->map->map[i][j] == 'E')
		(*main)->ecount++;
	if ((*main)->map->map[i][j] == 'M')
		(*main)->mcount++;
}
