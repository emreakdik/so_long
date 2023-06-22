/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakdik <yakdik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:50:04 by yakdik            #+#    #+#             */
/*   Updated: 2023/04/13 15:50:05 by yakdik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free(t_main *main)
{
	free(main->map);
	free(main->sprite);
}

void	ft_error(char *errormsg, t_main *main)
{
	int	i;

	i = 0;
	while (errormsg[i])
	{
		write(1, &errormsg[i], 1);
		i++;
	}
	write(1, "\n", 1);
	ft_free(main);
	exit(0);
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

void	virtual_map_free(int **v_map, t_main *main)
{
	int	i;

	i = 0;
	while (i < main->map->y)
	{
		free(v_map[i]);
		i++;
	}
	free(v_map);
}

int	ft_x_button(t_main *main)
{
	mlx_destroy_image(main->mlx, main->win);
	exit(0);
	return (0);
}