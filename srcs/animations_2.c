/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 11:45:50 by micheng           #+#    #+#             */
/*   Updated: 2023/08/06 11:50:39 by micheng          ###   ########.fr       */
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