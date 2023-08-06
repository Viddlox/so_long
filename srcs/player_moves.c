/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 00:07:57 by micheng           #+#    #+#             */
/*   Updated: 2023/08/06 11:00:00 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_trap(t_vars *vars, int code)
{
	if (code == 126)
	{
		if (!is_obstacle(vars->map[vars->pos.y - 1][vars->pos.x])
			&& vars->trap_count > 0)
			vars->map[vars->pos.y - 1][vars->pos.x] = 'T';
	}
	else if (code == 123)
	{
		if (!is_obstacle(vars->map[vars->pos.y][vars->pos.x - 1])
			&& vars->trap_count > 0)
			vars->map[vars->pos.y][vars->pos.x - 1] = 'T';
	}
	else if (code == 125)
	{
		if (!is_obstacle(vars->map[vars->pos.y + 1][vars->pos.x])
			&& vars->trap_count > 0)
			vars->map[vars->pos.y + 1][vars->pos.x] = 'T';
	}
	else if (code == 124)
	{
		if (!is_obstacle(vars->map[vars->pos.y][vars->pos.x + 1])
			&& vars->trap_count > 0)
			vars->map[vars->pos.y][vars->pos.x + 1] = 'T';
	}
	vars->trap_count--;
}

int	move_up(t_vars *vars)
{
	vars->play_dead = 0;
	if (vars->map[vars->pos.y - 1][vars->pos.x] == '1')
		return (0);
	if (vars->map[vars->pos.y - 1][vars->pos.x] == 'T')
		vars->trap_count++;
	if (vars->map[vars->pos.y - 1][vars->pos.x] == 'X'
		|| vars->map[vars->pos.y - 1][vars->pos.x] == 'Z')
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
	return (0);
}

int	move_down(t_vars *vars)
{
	vars->play_dead = 0;
	if (vars->map[vars->pos.y + 1][vars->pos.x] == '1')
		return (0);
	if (vars->map[vars->pos.y + 1][vars->pos.x] == 'T')
		vars->trap_count++;
	if (vars->map[vars->pos.y + 1][vars->pos.x] == 'X'
		|| vars->map[vars->pos.y + 1][vars->pos.x] == 'Z')
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
	return (0);
}

int	move_right(t_vars *vars)
{
	vars->play_dead = 0;
	if (vars->map[vars->pos.y][vars->pos.x + 1] == '1')
		return (0);
	if (vars->map[vars->pos.y][vars->pos.x + 1] == 'T')
		vars->trap_count++;
	if (vars->map[vars->pos.y][vars->pos.x + 1] == 'X'
		|| vars->map[vars->pos.y][vars->pos.x + 1] == 'Z')
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
	return (0);
}

int	move_left(t_vars *vars)
{
	vars->play_dead = 0;
	if (vars->map[vars->pos.y][vars->pos.x - 1] == '1')
		return (0);
	if (vars->map[vars->pos.y][vars->pos.x - 1] == 'T')
		vars->trap_count++;
	if (vars->map[vars->pos.y][vars->pos.x - 1] == 'X'
		|| vars->map[vars->pos.y][vars->pos.x - 1] == 'Z')
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
	return (0);
}
