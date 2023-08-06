/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:35:05 by micheng           #+#    #+#             */
/*   Updated: 2023/08/06 11:50:29 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h> //test

# define BUFFER_SIZE 1024

typedef struct s_queue
{
	int				cur_x;
	int				cur_y;
	struct s_queue	*next;
}	t_queue;

typedef struct s_parent
{
	int				parent_x;
	int				parent_y;
	struct s_parent	*next;
}	t_parent;

//Enemy and player positions
typedef struct s_pos
{
	int				x;
	int				y;
	int				prev_x;
	int				prev_y;
	int				x_en;
	int				y_en;
	int				prev_en_x;
	int				prev_en_y;
	int				dx;
	int				dy;
	struct s_pos	*next;
}	t_pos;

typedef struct s_trap
{
	int				x;
	int				y;
	int				enemy_trapped;
	int				enemy_trapped_count;
	struct s_trap	*next;
}	t_trap;

typedef struct s_trap_data
{
	t_trap	*head;
}	t_trap_data;

typedef struct s_tracker
{
	int					x;
	int					y;
	struct s_tracker	*next;
}	t_tracker;


typedef struct s_tracker_data
{
	t_tracker	*head;
}	t_tracker_data;

typedef struct s_parent_data
{
	t_parent	*head;
}	t_parent_data;

typedef struct s_queue_data
{
	t_queue	*head;
}	t_queue_data;

typedef struct s_pos_data
{
	t_pos	*head;
}	t_pos_data;

//In-game variables
typedef struct s_game
{
	int	steps;
}	t_game;

//mlx rendering
typedef struct s_ren
{
	void	*mlx;
	void	*win;
}	t_ren;

//static sprites
typedef struct s_sprites
{
	void	*player_1;
	void	*enemy_1;
	void	*collectible_1;
	void	*enemy_dummy_1;
	void	*bomb_1;
	void	*exit;
	void	*exit_unlocked;
	void	*floors;
	void	*walls;
	void	*player_dead;
	void	*trap_1;
}	t_sprites;

typedef enum s_player_anim_state
{
	PLAYER_MOVE_LEFT,
	PLAYER_MOVE_RIGHT,
	PLAYER_MOVE_UP,
	PLAYER_MOVE_DOWN
}	t_player_anim_state;

typedef enum s_enemy_anim_state
{
	ENEMY_MOVE_LEFT,
	ENEMY_MOVE_RIGHT,
	ENEMY_MOVE_UP,
	ENEMY_MOVE_DOWN,
	ENEMY_TELEPORT
}	t_enemy_anim_state;

typedef struct s_animations
{
	int		frame_count;
	void	*player_idle;
	void	*player_left_1;
	void	*player_left_2;
	void	*player_left_3;
	void	*player_right_1;
	void	*player_right_2;
	void	*player_right_3;
	void	*player_down_1;
	void	*player_down_2;
	void	*player_up_1;
	void	*player_up_2;
	void	*player_up_3;

	void	*enemy_idle;
	void	*enemy_left_1;
	void	*enemy_left_2;
	void	*enemy_left_3;
	void	*enemy_right_1;
	void	*enemy_right_2;
	void	*enemy_right_3;
	void	*enemy_down_1;
	void	*enemy_down_2;
	void	*enemy_up_1;
	void	*enemy_up_2;
	void	*enemy_up_3;
	void	*enemy_trapped_1;
	void	*enemy_trapped_2;
	void	*enemy_dummy_1;
	void	*enemy_dummy_2;

	void	*collectible_1;
	void	*collectible_2;
	void	*collectible_3;

	void	*enemy_teleport_1;
	void	*enemy_teleport_2;

	void	*trap_1;
	void	*trap_2;
	void	*trap_3;
	void	*trap_4;

	void	*bomb_1;
	void	*bomb_2;
	void	*bomb_3;
	void	*bomb_4;
}	t_animations;

//main variables for the game
typedef struct s_vars
{
	int					p_count;
	int					e_count;
	int					c_count;
	int					en_count;
	int					ext_count;
	int					trap_count;
	char				**map;
	int					map_h;
	int					map_l;
	int					play_dead;
	int					trap_counter;
	int					trap_flag;
	t_pos_data			*head_pos;
	t_queue_data		*head_queue;
	t_parent_data		*head_parent;
	t_tracker_data		*head_tracker;
	t_trap_data			*head_trap;
	t_pos				pos;
	t_game				game;
	t_ren				render;
	t_sprites			sprites;
	t_animations		animations;
	t_player_anim_state	player_animation_state;
	t_enemy_anim_state	enemy_animation_state;
}		t_vars;

//animations
int		animation(t_vars *vars);
void	collectibles_anim_init(t_vars *vars);
void	player_anim_init_1(t_vars *vars);
void	player_anim_init_2(t_vars *vars);
void	enemy_anim_init_1(t_vars *vars);
void	enemy_anim_init_2(t_vars *vars);
void	trap_anim_init(t_vars *vars);
void	bomb_anim_init(t_vars *vars);
void	player_animation_up_down(t_vars *vars);
void	player_animation_left_right(t_vars *vars);
void	collectible_animation(t_vars *vars);
void	enemy_animation_up_down(t_vars *vars);
void	enemy_animation_left_right(t_vars *vars);
void	bomb_animation(t_vars *vars);
void	trap_animation(t_vars *vars);

//map validation functions
int		check_file(int ac, char **av, t_vars *vars);
int		check_map(t_vars *vars);
int		check_path(t_vars *vars);
void	free_map(char **map, t_vars *vars);
char	**clone_map(t_vars *vars);

//player controls
int		move_up(t_vars *vars);
int		move_down(t_vars *vars);
int		move_left(t_vars *vars);
int		move_right(t_vars *vars);
void	play_dead(t_vars *vars);
void	place_trap(t_vars *vars, int code);

//event functions
void	print_win(char **map, t_vars *vars);
void	print_lose(char **map, t_vars *vars);

//rendering/mlx functions
int		keypress(int code, t_vars *vars);
int		dest_win(t_vars *vars);
void	render_sprites(t_vars *vars);
void	render_man_game(t_vars *vars);
void	set_animation_sprites(t_vars *vars);
void	init_sprites(t_vars *vars);
void	set_sprites(t_vars *vars, int x, int y);
void	render_sprites(t_vars *vars);

//enemy functions
void	init_enemy(t_vars *vars);
int		bfs(t_vars *vars, t_queue *new_step);
int		x_vectors(int x, int i);
int		y_vectors(int y, int i);
int		is_obstacle(char c);
void	enemy_path(t_vars *vars);
int		manhattan_distance(t_vars *vars, int x, int y);
void	find_dummies(t_vars *vars);

//linked list utils
int		get_queue_size(t_queue_data *head);
void	ft_del(void *content);
void	init_parent_list(t_parent_data **data, t_vars *vars);
void	init_queue_list(t_queue_data **data, t_vars *vars);
void	init_pos_list(t_pos_data **data, t_vars *vars);
void	init_tracker_list(t_tracker_data **data, t_vars *vars);
void	add_tracked_node(t_pos *data, t_vars *vars);
void	ft_clear_parent_data(t_parent_data **data);
void	ft_clear_pos_data(t_pos_data **data);
void	ft_clear_queue_data(t_queue_data **data);
void	ft_clear_tracked_data(t_tracker_data **data);
void	clear_tracker_nodes(t_vars *vars);
void	free_lists(t_vars *vars);

//gnl utils
char	*get_next_line(int fd);
int		ft_strlen_gnl(char *str);
char	*ft_strjoin_gnl(char *save, char *buf, int r);
int		ft_strchr_gnl(char *str, char c);

#endif