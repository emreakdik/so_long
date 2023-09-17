/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakdik <yakdik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:15:30 by yakdik            #+#    #+#             */
/*   Updated: 2023/09/17 15:24:56 by yakdik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_count(t_main *main)
{
	char	*str;
	str = ft_itoa(main->mcount);
	mlx_string_put(main->mlx, main->win, 10, 10, 0x1000000, "Move Count: ");
	mlx_string_put(main->mlx, main->win, 100, 10, 0x1000000, str);
	free(str);
}

void	ber_check(char *map_path)
{
	int	i;

	i = 0;
	while (map_path[i])
		i++;
	if (!(map_path[i - 1] == 'r' && map_path[i - 2] == 'e' && map_path[i
				- 3] == 'b' && map_path[i - 4] == '.'))
	{
		ft_error("Wrong file extension. It should be .ber extension.",
			NULL);
		exit(0);
	}
}

void	check_parameters(int ac, char **av)
{
	int	map_parameter_len;

	if (ac > 2)
		path_error("Too many arguments (It should be only two).");
	if (ac < 2)
		path_error("The Map file is missing.");
	map_parameter_len = ft_strlen(av[1]);
	if (!ft_strnstr(&av[1][map_parameter_len - 4], ".ber", 4))
		path_error("Map file extention is wrong (It should be .ber).");
}

void	bonus_convert_enemy(t_main *main)
{
	int	x;
	int	y;

	main->sprite->enemy[0] = mlx_xpm_file_to_image(
			main->mlx, "./images/enemy1.xpm", &x, &y);
	main->sprite->enemy[1] = mlx_xpm_file_to_image(
			main->mlx, "./images/enemy2.xpm", &x, &y);
}

void	path_error(char *errormsg)
{
	int	i;

	i = 0;
	while (errormsg[i])
	{
		write(1, &errormsg[i], 1);
		i++;
	}
	write(1, "\n", 1);
	exit(0);
}
