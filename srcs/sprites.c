/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 05:37:38 by micheng           #+#    #+#             */
/*   Updated: 2023/08/07 11:16:04 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_basic_sprites(t_vars *vars, int x, int y)
{
	if (vars->map[y][x] == '1')
		mlx_put_image_to_window(vars->render.mlx,vars->render.win,
			vars->sprites.walls, x * 32, y * 32);
	else if (vars->map[y][x] == '0')
	{
		if (vars->time_bomb.timer <= 0)
			mlx_put_image_to_window(vars->render.mlx,
				vars->render.win, vars->sprites.fire_1, x * 32, y * 32);
		else
			mlx_put_image_to_window(vars->render.mlx,
				vars->render.win, vars->sprites.floors, x * 32, y * 32);
	}
	else if (vars->map[y][x] == 'P')
	{
		if (vars->time_bomb.timer <= 0)
			mlx_put_image_to_window(vars->render.mlx,
				vars->render.win, vars->sprites.player_dead, x * 32, y * 32);
		else
			mlx_put_image_to_window(vars->render.mlx,
			vars->render.win, vars->sprites.player_1, x * 32, y * 32);
	}
	else if (vars->map[y][x] == 'C')
		mlx_put_image_to_window(vars->render.mlx,
			vars->render.win, vars->sprites.collectible_1, x * 32, y * 32);
	else if (vars->map[y][x] == 'E')
		mlx_put_image_to_window(vars->render.mlx,
			vars->render.win, vars->sprites.exit, x * 32, y * 32);
	else if (vars->map[y][x] == 'X')
		mlx_put_image_to_window(vars->render.mlx,
			vars->render.win, vars->sprites.enemy_1, x * 32, y * 32);
}

void	set_extra_sprites(t_vars *vars, int x, int y)
{
	if (vars->map[y][x] == 'D')
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
	else if (vars->map[y][x] == 'K')
		mlx_put_image_to_window(vars->render.mlx,
			vars->render.win, vars->sprites.key_1, x * 32, y * 32);
	else if (vars->map[y][x] == 'G')
		mlx_put_image_to_window(vars->render.mlx,
			vars->render.win, vars->sprites.explosion_1, x * 32, y * 32);
}

void	set_icons(t_vars *vars)
{
	mlx_put_image_to_window(vars->render.mlx,
		vars->render.win, vars->game.step_img, 10, 5);
	mlx_put_image_to_window(vars->render.mlx,
		vars->render.win, vars->game.trap_img, 10, 40);
	mlx_put_image_to_window(vars->render.mlx,
		vars->render.win, vars->game.bomb_img, 195, 1);
	mlx_put_image_to_window(vars->render.mlx,
		vars->render.win, vars->game.key_img, 1, 65);
}