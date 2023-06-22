/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakdik <yakdik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:50:18 by yakdik            #+#    #+#             */
/*   Updated: 2023/04/13 15:50:19 by yakdik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_main *main;

	main = (t_main *)malloc(sizeof(t_main));
	check_parameters(ac, av, main);
	main_initiliazer(av[1], &main);
	map_checker(main);
	virtual_map(main, 0, 0);
	draw_map(main);
	mlx_hook(main->win, 2, 1L << 0, key_hook, main);
	mlx_loop_hook(main->mlx, render, main);
	mlx_hook(main->win, 17, 0, ft_x_button, main);
	mlx_loop(main->mlx);
}