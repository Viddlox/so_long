/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 11:45:50 by micheng           #+#    #+#             */
/*   Updated: 2023/08/07 11:04:38 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	bomb_animation(t_vars *vars)
{
	if (vars->sprites.bomb_1 == vars->animations.bomb_1)
		vars->sprites.bomb_1 = vars->animations.bomb_2;
	else if (vars->sprites.bomb_1 == vars->animations.bomb_2)
		vars->sprites.bomb_1 = vars->animations.bomb_3;
	else if (vars->sprites.bomb_1 == vars->animations.bomb_3)
		vars->sprites.bomb_1 = vars->animations.bomb_4;
	else if (vars->sprites.bomb_1 == vars->animations.bomb_4)
		vars->sprites.bomb_1 = vars->animations.bomb_1;
}

void	trap_animation(t_vars *vars)
{
	if (vars->sprites.trap_1 == vars->animations.trap_1)
		vars->sprites.trap_1 = vars->animations.trap_2;
	else if (vars->sprites.trap_1 == vars->animations.trap_2)
		vars->sprites.trap_1 = vars->animations.trap_3;
	else if (vars->sprites.trap_1 == vars->animations.trap_3)
		vars->sprites.trap_1 = vars->animations.trap_4;
	else if (vars->sprites.trap_1 == vars->animations.trap_4)
		vars->sprites.trap_1 = vars->animations.trap_1;
}

void	key_animation(t_vars *vars)
{
	if (vars->sprites.key_1 == vars->animations.key_1)
		vars->sprites.key_1 = vars->animations.key_2;
	else if (vars->sprites.key_1 == vars->animations.key_2)
		vars->sprites.key_1 = vars->animations.key_3;
	else if (vars->sprites.key_1 == vars->animations.key_3)
		vars->sprites.key_1 = vars->animations.key_1;
}

void	use_key_animation(t_vars *vars)
{
	if (vars->sprites.use_key_1 == vars->animations.use_key_1)
		vars->sprites.use_key_1 = vars->animations.use_key_2;
	else if (vars->sprites.use_key_1 == vars->animations.use_key_2)
		vars->sprites.use_key_1 = vars->animations.player_idle;
}

void	explosion_animation(t_vars *vars)
{
	if (vars->sprites.explosion_1 == vars->animations.explosion_1)
		vars->sprites.explosion_1 = vars->animations.explosion_2;
	else if (vars->sprites.explosion_1 == vars->animations.explosion_2)
		vars->sprites.explosion_1 = vars->animations.explosion_3;
	else if (vars->sprites.explosion_1 == vars->animations.explosion_3)
		vars->sprites.explosion_1 = vars->animations.explosion_4;
	else if (vars->sprites.explosion_1 == vars->animations.explosion_4)
		vars->sprites.explosion_1 = vars->animations.explosion_5;
	else if (vars->sprites.explosion_1 == vars->animations.explosion_5)
		vars->sprites.explosion_1 = vars->animations.explosion_6;
	else if (vars->sprites.explosion_1 == vars->animations.explosion_6)
		vars->sprites.explosion_1 = vars->animations.explosion_7;
	else if (vars->sprites.explosion_1 == vars->animations.explosion_7)
		vars->sprites.explosion_1 = vars->animations.explosion_8;
	else if (vars->sprites.explosion_1 == vars->animations.explosion_8)
		vars->sprites.explosion_1 = vars->animations.explosion_9;
	else if (vars->sprites.explosion_1 == vars->animations.explosion_9)
		vars->sprites.explosion_1 = vars->animations.explosion_10;
	else if (vars->sprites.explosion_1 == vars->animations.explosion_10)
		vars->sprites.explosion_1 = vars->animations.explosion_11;
	else if (vars->sprites.explosion_1 == vars->animations.explosion_11)
		vars->sprites.explosion_1 = vars->animations.explosion_1;
}

void	fire_animation(t_vars *vars)
{
	if (vars->sprites.fire_1 == vars->animations.fire_1)
		vars->sprites.fire_1 = vars->animations.fire_2;
	else if (vars->sprites.fire_1 == vars->animations.fire_2)
		vars->sprites.fire_1 = vars->animations.fire_3;
	else if (vars->sprites.fire_1 == vars->animations.fire_3)
		vars->sprites.fire_1 = vars->animations.fire_4;
	else if (vars->sprites.fire_1 == vars->animations.fire_4)
		vars->sprites.fire_1 = vars->animations.fire_5;
	else if (vars->sprites.fire_1 == vars->animations.fire_5)
		vars->sprites.fire_1 = vars->animations.fire_6;
	else if (vars->sprites.fire_1 == vars->animations.fire_6)
		vars->sprites.fire_1 = vars->animations.fire_7;
	else if (vars->sprites.fire_1 == vars->animations.fire_7)
		vars->sprites.fire_1 = vars->animations.fire_8;
	else if (vars->sprites.fire_1 == vars->animations.fire_8)
		vars->sprites.fire_1 = vars->animations.fire_1;
	else if (vars->sprites.fire_1 == vars->animations.fire_1)
		vars->sprites.fire_1 = vars->animations.fire_2;
	else if (vars->sprites.fire_1 == vars->animations.fire_2)
		vars->sprites.fire_1 = vars->animations.fire_3;
	else if (vars->sprites.fire_1 == vars->animations.fire_3)
		vars->sprites.fire_1 = vars->animations.fire_4;
	else if (vars->sprites.fire_1 == vars->animations.fire_4)
		vars->sprites.fire_1 = vars->animations.fire_5;
	else if (vars->sprites.fire_1 == vars->animations.fire_5)
		vars->sprites.fire_1 = vars->animations.fire_6;
	else if (vars->sprites.fire_1 == vars->animations.fire_6)
		vars->sprites.fire_1 = vars->animations.fire_7;
	else if (vars->sprites.fire_1 == vars->animations.fire_7)
		vars->sprites.fire_1 = vars->animations.fire_8;
	else if (vars->sprites.fire_1 == vars->animations.fire_8)
		vars->sprites.fire_1 = vars->animations.fire_1;

}