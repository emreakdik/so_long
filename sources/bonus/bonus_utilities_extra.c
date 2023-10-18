/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utilities_extra.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakdik <yakdik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:37:39 by yakdik            #+#    #+#             */
/*   Updated: 2023/10/18 21:37:20 by yakdik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	map_cem_checker(t_main **main, int i, int j)
{
	if ((*main)->map->map[i][j] == 'C')
		(*main)->c_count++;
	if ((*main)->map->map[i][j] == 'E')
		(*main)->e_count++;
}
