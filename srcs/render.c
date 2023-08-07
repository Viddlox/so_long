/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 05:02:10 by micheng           #+#    #+#             */
/*   Updated: 2023/08/07 11:06:16 by micheng          ###   ########.fr       */
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
	key_anim_init(vars);
	explosion_anim_init(vars);
	fire_anim_init(vars);
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
	vars->sprites.key_1 = vars->animations.key_1;
	vars->sprites.use_key_1 = vars->animations.use_key_1;
	vars->sprites.explosion_1 = vars->animations.explosion_1;
	vars->sprites.fire_1 = vars->animations.fire_1;
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
			set_basic_sprites(vars, x, y);
			set_extra_sprites(vars, x, y);
			x++;
		}
		y++;
	}
	print_icons(vars);
	print_bomb_timer(vars);

}

int	animation(t_vars *vars)
{
	vars->animations.frame_count++;
	time_bomb_handler(vars);
	if (vars->animations.frame_count >= 2000)
	{
		if (vars->time_bomb.explosion_flag == 1)
		{
			mlx_clear_window(vars->render.mlx, vars->render.win);
			render_sprites(vars);
			explosion_animation(vars);
			fire_animation(vars);
			
			if (vars->time_bomb.timer <= -8000)
				print_lose(vars->map, vars);
		}
		if (vars->trap_flag == 1)
			activate_trap(vars);
		mlx_clear_window(vars->render.mlx, vars->render.win);
		collectible_animation(vars);
		bomb_animation(vars);
		trap_animation(vars);
		key_animation(vars);
		player_animation_left_right(vars);
		player_animation_up_down(vars);
		if (vars->en_count > 0)
			enemy_game_loop(vars);
		vars->animations.frame_count = 0;
		render_sprites(vars);
	}
	return (0);
}

