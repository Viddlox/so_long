/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:35:05 by micheng           #+#    #+#             */
/*   Updated: 2023/07/31 14:44:26 by micheng          ###   ########.fr       */
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
# include <stdbool.h>
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
	int				x_en;
	int				y_en;
	int				dx;
	int				dy;
	struct s_pos	*next;
}	t_pos;

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
	int	frame_count;
}	t_game;

//mlx rendering
typedef struct s_ren
{
	void	*mlx;
	void	*win;
	void	*player1_l;
	void	*player2_l;
	void	*player1_r;
	void	*player2_r;
	void	*enemy1_l;
	void	*enemy2_l;
	void	*enemy1_r;
	void	*enemy2_r;
	void	*exit_open;
	void	*exit_close;
}	t_ren;

//static sprites
typedef struct s_sprites
{
	void	*player;
	void	*enemy;
	void	*collectibles;
	void	*exit;
	void	*exit_unlocked;
	void	*floors;
	void	*walls;
}	t_sprites;

//main variables for the game
typedef struct s_vars
{
	int				p_count;
	int				e_count;
	int				c_count;
	int				en_count;
	int				ext_count;
	char			**map;
	int				map_h;
	int				map_l;
	t_pos_data		*head_pos;
	t_queue_data	*head_queue;
	t_parent_data	*head_parent;
	t_pos			pos;
	t_game			game;
	t_ren			render;
	t_sprites		sprites;
}		t_vars;

//map validation functions
int		check_file(int ac, char **av, t_vars *vars);
int		check_map(t_vars *vars);
int		check_path(t_vars *vars);
void	free_map(char **map, t_vars *vars);
char	**clone_map(t_vars *vars);

//movement functions
int		move_up(t_vars *vars);
int		move_down(t_vars *vars);
int		move_left(t_vars *vars);
int		move_right(t_vars *vars);

//event functions
void	print_win(char **map, t_vars *vars);
void	print_lose(char **map, t_vars *vars);
void	game_loop(t_vars *vars);

//rendering/mlx functions
int		keypress(int code, t_vars *vars);
int		dest_win(t_vars *vars);
void	render(t_vars *vars);
void	render_sprites(t_vars *vars);
void	render_game(t_vars *vars);

//enemy functions
void	init_enemy(t_vars *vars);
int		bfs(t_vars *vars, t_queue *new_step, char **map);
int		x_vectors(int x, int i);
int		y_vectors(int y, int i);
int		is_obstacle(char c);
void	enemy_path(t_vars *vars);

//linked list utils
int		get_queue_size(t_queue_data *head);
void	ft_del(void *content);
void	print_parent_list(t_parent *head);
void	init_parent_list(t_parent_data **data, t_vars *vars);
void	init_queue_list(t_queue_data **data, t_vars *vars);
void	init_pos_list(t_pos_data **data, t_vars *vars);
void	ft_clear_parent_data(t_parent_data **data);
void	ft_clear_pos_data(t_pos_data **data);
void	ft_clear_queue_data(t_queue_data **data);
void	free_lists(t_vars *vars);

//gnl utils
char	*get_next_line(int fd);
int		ft_strlen_gnl(char *str);
char	*ft_strjoin_gnl(char *save, char *buf, int r);
int		ft_strchr_gnl(char *str, char c);

#endif