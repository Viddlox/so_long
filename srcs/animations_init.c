/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 03:58:30 by micheng           #+#    #+#             */
/*   Updated: 2023/08/04 06:08:29 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collectibles_anim_init(t_vars *vars)
{
	int	x;
	int	y;

	vars->animations.collectible_1 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/collectible_1.xpm", &x, &y);
	vars->animations.collectible_2 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/collectible_2.xpm", &x, &y);
	vars->animations.collectible_3 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/collectible_3.xpm", &x, &y);
}

void	player_anim_init_1(t_vars *vars)
{
	int	x;
	int	y;

	vars->animations.player_idle = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/player_idle.xpm", &x, &y);
	vars->animations.player_left_1 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/player_left_1.xpm", &x, &y);
	vars->animations.player_left_2 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/player_left_2.xpm", &x, &y);
	vars->animations.player_left_3 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/player_left_3.xpm", &x, &y);
	vars->animations.player_right_1 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/player_right_1.xpm", &x, &y);
	vars->animations.player_right_2 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/player_right_2.xpm", &x, &y);
	vars->animations.player_right_3 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/player_right_3.xpm", &x, &y);
}

void	player_anim_init_2(t_vars *vars)
{
	int	x;
	int	y;

	vars->animations.player_down_1 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/player_down_1.xpm", &x, &y);
	vars->animations.player_down_2 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/player_down_2.xpm", &x, &y);
	vars->animations.player_up_1 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/player_up_1.xpm", &x, &y);
	vars->animations.player_up_2 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/player_up_2.xpm", &x, &y);
	vars->animations.player_up_3 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/player_up_3.xpm", &x, &y);
}

void	enemy_anim_init_1(t_vars *vars)
{
	int	x;
	int	y;

	vars->animations.enemy_idle = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/enemy_idle.xpm", &x, &y);
	vars->animations.enemy_left_1 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/enemy_left_1.xpm", &x, &y);
	vars->animations.enemy_left_2 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/enemy_left_2.xpm", &x, &y);
	vars->animations.enemy_left_3 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/enemy_left_3.xpm", &x, &y);
	vars->animations.enemy_right_1 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/enemy_right_1.xpm", &x, &y);
	vars->animations.enemy_right_2 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/enemy_right_2.xpm", &x, &y);
	vars->animations.enemy_right_3 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/enemy_right_3.xpm", &x, &y);
}

void	enemy_anim_init_2(t_vars *vars)
{
	int	x;
	int	y;

	vars->animations.enemy_down_1 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/enemy_down_1.xpm", &x, &y);
	vars->animations.enemy_down_2 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/enemy_down_2.xpm", &x, &y);
	vars->animations.enemy_up_1 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/enemy_up_1.xpm", &x, &y);
	vars->animations.enemy_up_2 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/enemy_up_2.xpm", &x, &y);
	vars->animations.enemy_up_3 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/enemy_up_3.xpm", &x, &y);
}