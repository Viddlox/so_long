/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 08:22:51 by micheng           #+#    #+#             */
/*   Updated: 2023/08/06 08:18:41 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collectible_animation(t_vars *vars)
{
	if (vars->sprites.collectible_1 == vars->animations.collectible_1)
		vars->sprites.collectible_1 = vars->animations.collectible_2;
	else if (vars->sprites.collectible_1 == vars->animations.collectible_2)
		vars->sprites.collectible_1 = vars->animations.collectible_3;
	else if (vars->sprites.collectible_1 == vars->animations.collectible_3)
		vars->sprites.collectible_1 = vars->animations.collectible_1;
	if (vars->sprites.trap_1 == vars->animations.trap_1)
		vars->sprites.trap_1 = vars->animations.trap_2;
	else if (vars->sprites.trap_1 == vars->animations.trap_2)
		vars->sprites.trap_1 = vars->animations.trap_3;
	else if (vars->sprites.trap_1 == vars->animations.trap_3)
		vars->sprites.trap_1 = vars->animations.trap_4;
	else if (vars->sprites.trap_1 == vars->animations.trap_4)
		vars->sprites.trap_1 = vars->animations.trap_1;
	if (vars->sprites.enemy_dummy_1 == vars->animations.enemy_trapped_1)
		vars->sprites.enemy_dummy_1 = vars->animations.enemy_trapped_2;
	else if (vars->sprites.enemy_dummy_1 == vars->animations.enemy_trapped_2)
		vars->sprites.enemy_dummy_1 = vars->animations.enemy_trapped_1;
}

void	player_animation_left_right(t_vars *vars)
{
	if (vars->player_animation_state == PLAYER_MOVE_LEFT)
	{
		if (vars->sprites.player_1 == vars->animations.player_left_1)
			vars->sprites.player_1 = vars->animations.player_left_2;
		else if (vars->sprites.player_1 == vars->animations.player_left_2)
			vars->sprites.player_1 = vars->animations.player_left_3;
		else if (vars->sprites.player_1 == vars->animations.player_left_3)
			vars->sprites.player_1 = vars->animations.player_idle;
	}
	else if (vars->player_animation_state == PLAYER_MOVE_RIGHT)
	{
		if (vars->sprites.player_1 == vars->animations.player_right_1)
			vars->sprites.player_1 = vars->animations.player_right_2;
		else if (vars->sprites.player_1 == vars->animations.player_right_2)
			vars->sprites.player_1 = vars->animations.player_right_3;
		else if (vars->sprites.player_1 == vars->animations.player_right_3)
			vars->sprites.player_1 = vars->animations.player_idle;
	}
	return ;
}

void	player_animation_up_down(t_vars *vars)
{
	if (vars->player_animation_state == PLAYER_MOVE_UP)
	{
		if (vars->sprites.player_1 == vars->animations.player_up_1)
			vars->sprites.player_1 = vars->animations.player_up_2;
		else if (vars->sprites.player_1 == vars->animations.player_up_2)
			vars->sprites.player_1 = vars->animations.player_up_3;
		else if (vars->sprites.player_1 == vars->animations.player_up_3)
			vars->sprites.player_1 = vars->animations.player_idle;
	}
	else if (vars->player_animation_state == PLAYER_MOVE_DOWN)
	{
		if (vars->sprites.player_1 == vars->animations.player_down_1)
			vars->sprites.player_1 = vars->animations.player_down_2;
		else if (vars->sprites.player_1 == vars->animations.player_down_2)
			vars->sprites.player_1 = vars->animations.player_idle;
	}
	return ;
}

void	enemy_animation_up_down(t_vars *vars)
{
	if (vars->enemy_animation_state == ENEMY_MOVE_UP)
	{
		if (vars->sprites.enemy_1 == vars->animations.enemy_up_1)
			vars->sprites.enemy_1 = vars->animations.enemy_up_2;
		else if (vars->sprites.enemy_1 == vars->animations.enemy_up_2)
			vars->sprites.enemy_1 = vars->animations.enemy_up_3;
		else if (vars->sprites.enemy_1 == vars->animations.enemy_up_3)
			vars->sprites.enemy_1 = vars->animations.enemy_idle;
	}
	else if (vars->enemy_animation_state == ENEMY_MOVE_DOWN)
	{
		if (vars->sprites.enemy_1 == vars->animations.enemy_down_1)
			vars->sprites.enemy_1 = vars->animations.enemy_down_2;
		else if (vars->sprites.enemy_1 == vars->animations.enemy_down_2)
			vars->sprites.enemy_1 = vars->animations.enemy_idle;
	}
	return ;
}

void	enemy_animation_left_right(t_vars *vars)
{
	if (vars->enemy_animation_state == ENEMY_MOVE_LEFT)
	{
		if (vars->sprites.enemy_1 == vars->animations.enemy_left_1)
			vars->sprites.enemy_1 = vars->animations.enemy_left_2;
		else if (vars->sprites.enemy_1 == vars->animations.enemy_left_2)
			vars->sprites.enemy_1 = vars->animations.enemy_left_3;
		else if (vars->sprites.enemy_1 == vars->animations.enemy_left_3)
			vars->sprites.enemy_1 = vars->animations.enemy_idle;
	}
	else if (vars->enemy_animation_state == ENEMY_MOVE_RIGHT)
	{
		if (vars->sprites.enemy_1 == vars->animations.enemy_right_1)
			vars->sprites.enemy_1 = vars->animations.enemy_right_2;
		else if (vars->sprites.enemy_1 == vars->animations.enemy_right_2)
			vars->sprites.enemy_1 = vars->animations.enemy_right_3;
		else if (vars->sprites.enemy_1 == vars->animations.enemy_right_3)
			vars->sprites.enemy_1 = vars->animations.enemy_idle;
	}
	return ;
}