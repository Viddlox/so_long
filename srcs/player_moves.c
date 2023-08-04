/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 00:07:57 by micheng           #+#    #+#             */
/*   Updated: 2023/08/04 04:10:21 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_up(t_vars *vars)
{
	if (vars->map[vars->pos.y - 1][vars->pos.x] == '1')
		return (0);
	if (vars->map[vars->pos.y - 1][vars->pos.x] == 'X')
		print_lose(vars->map, vars);
	if (vars->map[vars->pos.y - 1][vars->pos.x] == 'C')
		vars->c_count--;
	if (vars->map[vars->pos.y - 1][vars->pos.x] == 'E' &&
	vars->c_count > 0)
		return (0);
	if (vars->map[vars->pos.y - 1][vars->pos.x] == 'E' && vars->c_count == 0)
		print_win(vars->map, vars);
	vars->map[vars->pos.y][vars->pos.x] = '0';
	vars->map[vars->pos.y - 1][vars->pos.x] = 'P';
	vars->pos.y--;
	if (vars->c_count == 0)
		vars->sprites.exit = vars->sprites.exit_unlocked;
	vars->sprites.player_1 = vars->animations.player_up_1;
	vars->player_animation_state = PLAYER_MOVE_UP;
	vars->game.steps++;
	mlx_clear_window(vars->render.mlx, vars->render.win);
	return (0);
}

int	move_down(t_vars *vars)
{
	if (vars->map[vars->pos.y + 1][vars->pos.x] == '1')
		return (0);
	if (vars->map[vars->pos.y + 1][vars->pos.x] == 'X')
		print_lose(vars->map, vars);
	if (vars->map[vars->pos.y + 1][vars->pos.x] == 'C')
		vars->c_count--;
	if (vars->map[vars->pos.y + 1][vars->pos.x] == 'E' &&
	vars->c_count > 0)
		return (0);
	if (vars->map[vars->pos.y + 1][vars->pos.x] == 'E' && vars->c_count == 0)
		print_win(vars->map, vars);
	vars->map[vars->pos.y][vars->pos.x] = '0';
	vars->map[vars->pos.y + 1][vars->pos.x] = 'P';
	vars->pos.y++;
	if (vars->c_count == 0)
		vars->sprites.exit = vars->sprites.exit_unlocked;
	vars->sprites.player_1 = vars->animations.player_down_1;
	vars->player_animation_state = PLAYER_MOVE_DOWN;
	vars->game.steps++;
	mlx_clear_window(vars->render.mlx, vars->render.win);
	return (0);
}

int	move_right(t_vars *vars)
{
	if (vars->map[vars->pos.y][vars->pos.x + 1] == '1')
		return (0);
	if (vars->map[vars->pos.y][vars->pos.x + 1] == 'X')
		print_lose(vars->map, vars);
	if (vars->map[vars->pos.y][vars->pos.x + 1] == 'C')
		vars->c_count--;
	if (vars->map[vars->pos.y][vars->pos.x + 1] == 'E' &&
	vars->c_count > 0)
		return (0);
	if (vars->map[vars->pos.y][vars->pos.x + 1] == 'E' && vars->c_count == 0)
		print_win(vars->map, vars);
	vars->map[vars->pos.y][vars->pos.x] = '0';
	vars->map[vars->pos.y][vars->pos.x + 1] = 'P';
	vars->pos.x++;
	if (vars->c_count == 0)
		vars->sprites.exit = vars->sprites.exit_unlocked;
	vars->sprites.player_1 = vars->animations.player_right_1;
	vars->player_animation_state = PLAYER_MOVE_RIGHT;
	vars->game.steps++;
	mlx_clear_window(vars->render.mlx, vars->render.win);
	return (0);
}

int	move_left(t_vars *vars)
{
	if (vars->map[vars->pos.y][vars->pos.x - 1] == '1')
		return (0);
	if (vars->map[vars->pos.y][vars->pos.x - 1] == 'X')
		print_lose(vars->map, vars);
	if (vars->map[vars->pos.y][vars->pos.x - 1] == 'C')
		vars->c_count--;
	if (vars->map[vars->pos.y][vars->pos.x - 1] == 'E' &&
	vars->c_count > 0)
		return (0);
	if (vars->map[vars->pos.y][vars->pos.x - 1] == 'E' && vars->c_count == 0)
		print_win(vars->map, vars);
	vars->map[vars->pos.y][vars->pos.x] = '0';
	vars->map[vars->pos.y][vars->pos.x - 1] = 'P';
	vars->pos.x--;
	if (vars->c_count == 0)
		vars->sprites.exit = vars->sprites.exit_unlocked;
	vars->sprites.player_1 = vars->animations.player_left_1;
	vars->player_animation_state = PLAYER_MOVE_LEFT;
	vars->game.steps++;
	mlx_clear_window(vars->render.mlx, vars->render.win);
	return (0);
}
