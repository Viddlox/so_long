/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 05:02:10 by micheng           #+#    #+#             */
/*   Updated: 2023/08/03 08:01:12 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_animation_sprites(t_vars *vars)
{
	int	x;
	int	y;

	vars->animations.collectible_2 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/collectible_2.xpm", &x, &y);
	vars->animations.collectible_3 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/collectible_3.xpm", &x, &y);
	vars->animations.collectible_4 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/collectible_4.xpm", &x, &y);
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

static void	init_sprites(t_vars *vars)
{
	int	x;
	int	y;

	vars->sprites.collectible_1 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/collectible_1.xpm", &x, &y);
	vars->sprites.walls = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/wall.xpm", &x, &y);
	vars->sprites.floors = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/floor.xpm", &x, &y);
	vars->sprites.player_1 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/player_idle.xpm", &x, &y);
	vars->sprites.enemy = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/enemy.xpm", &x, &y);
	vars->sprites.exit = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/exit.xpm", &x, &y);
	vars->sprites.exit_unlocked = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/exit_unlocked.xpm", &x, &y);
}

static void	set_sprites(t_vars *vars, int x, int y)
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
			vars->render.win, vars->sprites.enemy, x * 32, y * 32);
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
}

void	render(t_vars *vars)
{
	vars->render.mlx = mlx_init();
	vars->render.win = mlx_new_window(vars->render.mlx,
			vars->map_l * 32, vars->map_h * 32, "so_long");
	init_sprites(vars);
	set_animation_sprites(vars);

	if (vars->en_count > 0)
		game_loop(vars);
	else
	{
		mlx_hook(vars->render.win, 2, (1L << 0), keypress, vars);
		mlx_hook(vars->render.win, 17, 0L, dest_win, vars);
		mlx_loop_hook(vars->render.mlx, (int (*)(void *))animation, vars);
		mlx_loop(vars->render.mlx);
	}
}
