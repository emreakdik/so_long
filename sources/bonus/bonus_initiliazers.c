/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_initiliazers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakdik <yakdik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:50:23 by yakdik            #+#    #+#             */
/*   Updated: 2023/10/18 21:46:40 by yakdik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"
#include <stdlib.h>
#include <fcntl.h>

void	bonus_convert_null(t_main *main)
{
	main->sprite->player_right[2] = NULL;
	main->sprite->player_left[2] = NULL;
	main->sprite->player_down[2] = NULL;
	main->sprite->player_up[2] = NULL;
	main->sprite->enemy[2] = NULL;
	main->sprite->bonus_wall[2] = NULL;
}

static char	**bonus_map_initiliazer(char *path, t_main *main)
{
	char	*line;
	int		i;
	int		fd;
	char	*temp;
	char	**map;

	fd = open(path, O_RDONLY);
	main->map->x = column_counter(path);
	main->map->y = line_counter(path);
	map = (char **)malloc(sizeof(char *) * (main->map->y + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (i < main->map->y)
	{
		temp = get_next_line(fd);
		line = ft_strtrim(temp, "\n");
		map[i] = line;
		free(temp);
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

int	bonus_main_initiliazer(char *path, t_main **main)
{
	char	*title;

	title = "so_long";
	(*main)->map = (t_map *)malloc(sizeof(t_map));
	if (!(*main)->map)
		return (1);
	(*main)->sprite = (t_sprite *)malloc(sizeof(t_sprite));
	if (!(*main)->sprite)
		return (free((*main)->map), 1);
	(*main)->read_count = 0;
	(*main)->p_count = 0;
	(*main)->c_count = 0;
	(*main)->e_count = 0;
	(*main)->m_count = 0;
	(*main)->i = 0;
	(*main)->j = 0;
	(*main)->mlx = mlx_init();
	(*main)->map->map = bonus_map_initiliazer(path, *main);
	if (!(*main)->map->map)
		return (free((*main)->sprite), free((*main)->map), 1);
	(*main)->win = mlx_new_window((*main)->mlx, ((*main)->map->x - 1) * PIXEL,
			(*main)->map->y * PIXEL, title);
	return (0);
}
