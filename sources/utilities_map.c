/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakdik <yakdik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:22:36 by yakdik            #+#    #+#             */
/*   Updated: 2023/04/14 13:24:32 by yakdik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	bonus_convert_null(t_main *main)
{
	main->sprite->player_right[2] = NULL;
	main->sprite->player_left[2] = NULL;
	main->sprite->player_down[2] = NULL;
	main->sprite->player_up[2] = NULL;
	main->sprite->enemy[2] = NULL;
	main->sprite->bonus_wall[2] = NULL;
}

int	column_counter(char *path)
{
	int		count;
	char	*line;
	int		fd;

	count = 0;
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	while (line[count] != '\0')
	{
		count++;
	}
	free(line);
	return (count);
}

int	line_counter(char *path)
{
	int		count;
	char	*line;
	int		fd;

	count = 0;
	fd = open(path, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		count++;
		free(line);
	}
	return (count);
}

void	animation_timer(t_main *main)
{
	if (main->loopcount % 40 == 0)
		main->i = !main->i;
}

void	animation_timer_wall(t_main *main)
{
	if (main->loopcount % 20 == 0)
		main->j = !main->j;
}
