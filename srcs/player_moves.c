/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 00:07:57 by micheng           #+#    #+#             */
/*   Updated: 2023/08/07 23:57:26 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_interactions(t_vars *vars, int code)
{
	if (code == 126)
	{
		if (vars->map[vars->pos.y - 1][vars->pos.x] == 'B' && vars->k_left_count >= 1)
			defuse_bomb(vars);
		else if (!is_obstacle(vars->map[vars->pos.y - 1][vars->pos.x])
			&& vars->trap_count > 0)
		{
			vars->map[vars->pos.y - 1][vars->pos.x] = 'T';
			vars->trap_count--;
		}
	}
	else if (code == 123)
	{
		if (vars->map[vars->pos.y][vars->pos.x - 1] == 'B' && vars->k_left_count >= 1)
			defuse_bomb(vars);
		else if (!is_obstacle(vars->map[vars->pos.y][vars->pos.x - 1])
			&& vars->trap_count > 0)
		{
			vars->map[vars->pos.y][vars->pos.x - 1] = 'T';
			vars->trap_count--;
		}
	}
	else if (code == 125)
	{
		if (vars->map[vars->pos.y + 1][vars->pos.x] == 'B' && vars->k_left_count >= 1)
			defuse_bomb(vars);
		else if (!is_obstacle(vars->map[vars->pos.y + 1][vars->pos.x])
			&& vars->trap_count > 0)
		{
			vars->map[vars->pos.y + 1][vars->pos.x] = 'T';
			vars->trap_count--;
		}
	}
	else if (code == 124)
	{
		if (vars->map[vars->pos.y][vars->pos.x + 1] == 'B' && vars->k_left_count >= 1)
			defuse_bomb(vars);
		if (!is_obstacle(vars->map[vars->pos.y][vars->pos.x + 1])
			&& vars->trap_count > 0)
		{
			vars->map[vars->pos.y][vars->pos.x + 1] = 'T';
			vars->trap_count--;
		}
	}
}

int	move_up(t_vars *vars)
{
	vars->play_dead = 0;
	if (vars->map[vars->pos.y - 1][vars->pos.x] == '1'
		|| vars->map[vars->pos.y - 1][vars->pos.x] == 'B'
		|| vars->map[vars->pos.y - 1][vars->pos.x] == 'O')
		return (0);
	if (vars->map[vars->pos.y - 1][vars->pos.x] == 'T')
		vars->trap_count++;
	if (vars->map[vars->pos.y - 1][vars->pos.x] == 'X'
		|| vars->map[vars->pos.y - 1][vars->pos.x] == 'Z')
		print_lose(vars->map, vars);
	if (vars->map[vars->pos.y - 1][vars->pos.x] == 'C')
		vars->c_count--;
	if (vars->map[vars->pos.y - 1][vars->pos.x] == 'K')
		vars->k_left_count++;
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
	if (vars->map[vars->pos.y + 1][vars->pos.x] == '1'
		|| vars->map[vars->pos.y + 1][vars->pos.x] == 'B'
		|| vars->map[vars->pos.y + 1][vars->pos.x] == 'O')
		return (0);
	if (vars->map[vars->pos.y + 1][vars->pos.x] == 'T')
		vars->trap_count++;
	if (vars->map[vars->pos.y + 1][vars->pos.x] == 'X'
		|| vars->map[vars->pos.y + 1][vars->pos.x] == 'Z')
		print_lose(vars->map, vars);
	if (vars->map[vars->pos.y + 1][vars->pos.x] == 'C')
		vars->c_count--;
	if (vars->map[vars->pos.y + 1][vars->pos.x] == 'K')
		vars->k_left_count++;
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
	if (vars->map[vars->pos.y][vars->pos.x + 1] == '1'
		|| vars->map[vars->pos.y][vars->pos.x + 1] == 'B'
		|| vars->map[vars->pos.y][vars->pos.x + 1] == 'O')
		return (0);
	if (vars->map[vars->pos.y][vars->pos.x + 1] == 'T')
		vars->trap_count++;
	if (vars->map[vars->pos.y][vars->pos.x + 1] == 'X'
		|| vars->map[vars->pos.y][vars->pos.x + 1] == 'Z')
		print_lose(vars->map, vars);
	if (vars->map[vars->pos.y][vars->pos.x + 1] == 'C')
		vars->c_count--;
	if (vars->map[vars->pos.y][vars->pos.x + 1] == 'K')
		vars->k_left_count++;
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
	if (vars->map[vars->pos.y][vars->pos.x - 1] == '1'
		|| vars->map[vars->pos.y][vars->pos.x - 1] == 'B'
		|| vars->map[vars->pos.y][vars->pos.x - 1] == 'O')
		return (0);
	if (vars->map[vars->pos.y][vars->pos.x - 1] == 'T')
		vars->trap_count++;
	if (vars->map[vars->pos.y][vars->pos.x - 1] == 'X'
		|| vars->map[vars->pos.y][vars->pos.x - 1] == 'Z')
		print_lose(vars->map, vars);
	if (vars->map[vars->pos.y][vars->pos.x - 1] == 'C')
		vars->c_count--;
	if (vars->map[vars->pos.y][vars->pos.x - 1] == 'K')
		vars->k_left_count++;
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
