/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakdik <yakdik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:51:00 by yakdik            #+#    #+#             */
/*   Updated: 2023/04/13 15:51:01 by yakdik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../library/libft/libft.h"
# include "../library/minilibx_opengl/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define FRAME 3

# if defined(__APPLE__) && defined(__MACH__)
#  define ESC 53
#  define W 13
#  define A 0
#  define S 1
#  define D 2
# else
#  define ESC 65307
#  define W 119
#  define A 97
#  define S 115
#  define D 100

# endif

# define PIXEL 32

typedef struct s_sprite
{
	void		*tile;
	void		*open_chest;
	void		*exit;
	void		*coin;
	void		*player;
	void		*bonus_wall[FRAME];
	void		*enemy[FRAME];
	void		*player_up[FRAME];
	void		*player_down[FRAME];
	void		*player_right[FRAME];
	void		*player_left[FRAME];
	char		player_direction;
	void		*wall;
	void		*fences;
	int			sprite_h;
	int			sprite_w;
}				t_sprite;

typedef struct s_map
{
	char		**map;
	int			x;
	int			y;

}				t_map;

typedef struct s_main
{
	void		*mlx;
	void		*win;
	void		*img;
	int			pcount;
	int			ccount;
	int			ecount;
	int			mcount;
	int			read_count;
	int			player_x;
	int			player_y;
	int			flag;
	int			i;
	int			j;
	int			loopcount;
	t_map		*map;
	t_sprite	*sprite;
}				t_main;

// Checks
void			check_parameters(int ac, char **av, t_main *game);
int				map_wall_checker(t_main *main);
void			ber_check(char *map_path);
int				map_checker(t_main *main);

// Initiliazers
void			main_initiliazer(char *map_path, t_main **main);
char			**map_initiliazer(char *path, t_main *main);
int				line_counter(char *path);
int				column_counter(char *path);

// Map Utilities
void			virtual_map(t_main *main, int y, int x);
void			virtual_map_free(int **v_map, t_main *main);
void			draw_map(t_main *main);

// Utilities
void			ft_error(char *errormsg, t_main *main);
int				key_hook(int keycode, t_main *main);
int				ft_x_button(t_main *main);
void			ft_free(t_main *main);
int				render(t_main *main);

// Bonus
int				bonus_key_hook(int keycode, t_main *main);
int				bonus_render(t_main *main);
void			bonus_draw_map(t_main *main);

#endif
