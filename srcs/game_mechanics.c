/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_mechanics.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 02:58:50 by micheng           #+#    #+#             */
/*   Updated: 2023/08/07 08:38:05 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	vars_init(t_vars *vars)
{
	vars->animations.frame_count = 0;
	vars->play_dead = 0;
	vars->trap_count = 5;
	vars->trap_flag = 0;
	vars->time_bomb.timer = 160000;
	vars->time_bomb.bomb_flag = 0;
	vars->game.steps = 0;
	vars->k_left_count = 0;
}

void	time_bomb_handler(t_vars *vars)
{
	vars->time_bomb.bomb_flag = 1;
	if (vars->k_count == 0 && vars->time_bomb.defuse_count == 0)
	{
		vars->time_bomb.bomb_flag = 0;
		return ;
	}
	vars->time_bomb.timer--;
	if (vars->time_bomb.timer <= 0 && vars->k_count > 0
		&& vars->time_bomb.defuse_count > 0)
	{
		// print_lose(vars->map, vars);
		return ;
	}
	
}

// void	defuse_bomb(t_vars *vars, int code)
// {
	
// }

void	activate_trap(t_vars *vars)
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
}

void	enemy_game_loop(t_vars *vars)
{
	init_pos_list(&vars->head_pos, vars);
	init_parent_list(&vars->head_parent, vars);
	init_enemy(vars);
	enemy_animation_left_right(vars);
	enemy_animation_up_down(vars);
	free_lists(vars);
}