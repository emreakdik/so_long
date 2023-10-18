/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_so_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakdik <yakdik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:50:27 by yakdik            #+#    #+#             */
/*   Updated: 2023/10/18 21:57:43 by yakdik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

static void	path_check(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		path_error("Error\nInvalid path");
	}
}

int	main(int ac, char **av)
{
	t_main	*main;

	check_parameters(ac, av);
	path_check(av[1]);
	main = (t_main *)malloc(sizeof(t_main));
	if (!main)
		return (0);
	if (bonus_main_initiliazer(av[1], &main))
		return (free(main), 0);
	bonus_map_checker(main);
	if (virtual_map(main, 0, 0))
		return (ft_free(main), 0);
	if (bonus_draw_map(main))
		return (write(2, "Error\nxpm file not found", 24), 0);
	mlx_hook(main->win, 2, 1L << 0, bonus_key_hook, main);
	mlx_loop_hook(main->mlx, bonus_render, main);
	mlx_hook(main->win, 17, 0, ft_x_button, main);
	mlx_loop(main->mlx);
}
