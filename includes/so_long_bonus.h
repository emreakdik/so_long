/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakdik <yakdik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:51:00 by yakdik            #+#    #+#             */
/*   Updated: 2023/10/18 21:47:03 by yakdik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../library/libft/libft.h"
# include "../library/minilibx_opengl/mlx.h"

# define FRAME 3

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

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
	int			p_count;
	int			c_count;
	int			e_count;
	int			m_count;
	int			read_count;
	int			player_x;
	int			player_y;
	int			i;
	int			j;
	int			loop_count;
	t_map		*map;
	t_sprite	*sprite;
}				t_main;

// Initiliazers
int				bonus_main_initiliazer(char *map_path, t_main **main);
int				line_counter(char *path);
int				column_counter(char *path);

// Checks
void			check_parameters(int ac, char **av);
void			map_wall_checker(t_main *main);
void			ber_check(char *map_path);
void			bonus_map_checker(t_main *main);
void			bonus_map_control(t_main *main, int i, int j);

// Map Utilities
int				virtual_map(t_main *main, int y, int x);
void			path_error(char *errormsg);
void			map_cem_checker(t_main **main, int i, int j);

// Error Utilities
void			virtual_map_free(int **v_map, t_main *main);
int				ft_x_button(t_main *main);
void			ft_free(t_main *main);
void			ft_error(char *errormsg, t_main *main);

// Game Utilities
void			ber_check(char *map_path);

// Bonus
int				bonus_key_hook(int keycode, t_main *main);
int				bonus_render(t_main *main);
int				bonus_draw_map(t_main *main);
int				bonus_convert_enemy(t_main *main);
void			bonus_convert_null(t_main *main);
void			print_count(t_main *main);
void			animation_timer(t_main *main);
void			animation_timer_wall(t_main *main);

#endif
