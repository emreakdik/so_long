/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakdik <yakdik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:44:28 by yakdik            #+#    #+#             */
/*   Updated: 2023/10/18 21:52:13 by yakdik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"
#include <stdlib.h>

int	bonus_convert_enemy(t_main *main)
{
	int	x;
	int	y;

	main->sprite->enemy[0] = mlx_xpm_file_to_image(main->mlx,
			"./images/enemy1.xpm", &x, &y);
	main->sprite->enemy[1] = mlx_xpm_file_to_image(main->mlx,
			"./images/enemy2.xpm", &x, &y);
	if (!main->sprite->enemy[0] || !main->sprite->enemy[1])
		return (1);
	return (0);
}

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

void	print_count(t_main *main)
{
	char	*str;

	str = ft_itoa(main->m_count);
	mlx_string_put(main->mlx, main->win, 10, 10, 0x1000000, "Move Count: ");
	mlx_string_put(main->mlx, main->win, 100, 10, 0x1000000, str);
	free(str);
}

void	animation_timer(t_main *main)
{
	if (main->loop_count % 40 == 0)
		main->i = !main->i;
}

void	animation_timer_wall(t_main *main)
{
	if (main->loop_count % 20 == 0)
		main->j = !main->j;
}
