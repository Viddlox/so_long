/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 05:02:10 by micheng           #+#    #+#             */
/*   Updated: 2023/08/07 02:37:39 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_animation_sprites(t_vars *vars)
{
	collectibles_anim_init(vars);
	trap_anim_init(vars);
	bomb_anim_init(vars);
	player_anim_init_1(vars);
	player_anim_init_2(vars);
	enemy_anim_init_1(vars);
	enemy_anim_init_2(vars);
}

void	init_sprites(t_vars *vars)
{
	int	x;
	int	y;

	vars->sprites.walls = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/wall.xpm", &x, &y);
	vars->sprites.floors = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/floor.xpm", &x, &y);
	vars->sprites.exit = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/exit.xpm", &x, &y);
	vars->sprites.exit_unlocked = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/exit_unlocked.xpm", &x, &y);
	vars->sprites.player_dead = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/player_dead.xpm", &x, &y);
	set_animation_sprites(vars);
	vars->sprites.player_1 = vars->animations.player_idle;
	vars->sprites.collectible_1 = vars->animations.collectible_1;
	vars->sprites.enemy_1 = vars->animations.enemy_idle;
	vars->sprites.trap_1 = vars->animations.trap_1;
	vars->sprites.enemy_dummy_1 = vars->animations.enemy_trapped_1;
	vars->sprites.bomb_1 = vars->animations.bomb_1;
}

void	set_sprites(t_vars *vars, int x, int y)
{
	if (vars->map[y][x] == '1')
		mlx_put_image_to_window(vars->render.mlx,vars->render.win,
			vars->sprites.walls, x * 32, y * 32);
	else if (vars->map[y][x] == '0')
		mlx_put_image_to_window(vars->render.mlx,
			vars->render.win, vars->sprites.floors, x * 32, y * 32);
	else if (vars->map[y][x] == 'P')
		mlx_put_image_to_window(vars->render.mlx,
			vars->render.win, vars->sprites.player_1, x * 32, y * 32);
	else if (vars->map[y][x] == 'C')
		mlx_put_image_to_window(vars->render.mlx,
			vars->render.win, vars->sprites.collectible_1, x * 32, y * 32);
	else if (vars->map[y][x] == 'E')
		mlx_put_image_to_window(vars->render.mlx,
			vars->render.win, vars->sprites.exit, x * 32, y * 32);
	else if (vars->map[y][x] == 'X')
		mlx_put_image_to_window(vars->render.mlx,
			vars->render.win, vars->sprites.enemy_1, x * 32, y * 32);
	else if (vars->map[y][x] == 'D')
		mlx_put_image_to_window(vars->render.mlx,
			vars->render.win, vars->sprites.player_dead, x * 32, y * 32);
	else if (vars->map[y][x] == 'T')
		mlx_put_image_to_window(vars->render.mlx,
			vars->render.win, vars->sprites.trap_1, x * 32, y * 32);
	else if (vars->map[y][x] == 'Z')
		mlx_put_image_to_window(vars->render.mlx,
			vars->render.win, vars->sprites.enemy_dummy_1, x * 32, y * 32);
	else if (vars->map[y][x] == 'B')
		mlx_put_image_to_window(vars->render.mlx,
			vars->render.win, vars->sprites.bomb_1, x * 32, y * 32);
	mlx_put_image_to_window(vars->render.mlx,
		vars->render.win, vars->game.step_img, 10, 10);
	mlx_put_image_to_window(vars->render.mlx,
		vars->render.win, vars->game.trap_img, 10, 45);
	mlx_put_image_to_window(vars->render.mlx,
		vars->render.win, vars->game.bomb_img, 1, 60);
}

void	render_sprites(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			set_sprites(vars, x, y);
			x++;
		}
		y++;
	}
	print_steps(vars);
	print_trap_count(vars);
}

int	animation(t_vars *vars)
{
	vars->animations.frame_count++;
	if (vars->animations.frame_count >= 2000)
	{
		if (vars->trap_flag == 1)
		{
			vars->trap_counter--;
			if (vars->trap_counter <= 0)
			{
				find_dummies(vars);
				vars->trap_flag = 0;
			}
		}
		mlx_clear_window(vars->render.mlx, vars->render.win);
		collectible_animation(vars);
		bomb_animation(vars);
		trap_animation(vars);
		player_animation_left_right(vars);
		player_animation_up_down(vars);
		if (vars->en_count > 0)
		{
			init_pos_list(&vars->head_pos, vars);
			init_parent_list(&vars->head_parent, vars);
			init_enemy(vars);
			enemy_animation_left_right(vars);
			enemy_animation_up_down(vars);
			free_lists(vars);
		}
		vars->animations.frame_count = 0;
		render_sprites(vars);
	}
	return (0);
}

