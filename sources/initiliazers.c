/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiliazers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakdik <yakdik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:50:23 by yakdik            #+#    #+#             */
/*   Updated: 2023/04/13 15:50:24 by yakdik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**map_initiliazer(char *path, t_main *main)
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

void	main_initiliazer(char *path, t_main **main)
{
	char *title = "so_long";

	(*main)->map = (t_map *)malloc(sizeof(t_map));
	(*main)->sprite = (t_sprite *)malloc(sizeof(t_sprite));
	(*main)->read_count = 0;
	(*main)->pcount = 0;
	(*main)->ccount = 0;
	(*main)->ecount = 0;
	(*main)->mcount = 0;
	(*main)->i = 0;
	(*main)->j = 0;

	(*main)->mlx = mlx_init();
	(*main)->map->map = map_initiliazer(path, *main);
	(*main)->win = mlx_new_window(
		(*main)->mlx, ((*main)->map->x - 1) * PIXEL, (*main)->map->y * PIXEL, title);
}