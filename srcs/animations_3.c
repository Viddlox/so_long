/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 23:41:50 by micheng           #+#    #+#             */
/*   Updated: 2023/08/07 23:58:23 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	portal_animation(t_vars *vars)
{
	if (vars->sprites.portal_1 == vars->animations.portal_1)
		vars->sprites.portal_1 = vars->animations.portal_2;
	else if (vars->sprites.portal_1 == vars->animations.portal_2)
		vars->sprites.portal_1 = vars->animations.portal_3;
	else if (vars->sprites.portal_1 == vars->animations.portal_3)
		vars->sprites.portal_1 = vars->animations.portal_4;
	else if (vars->sprites.portal_1 == vars->animations.portal_4)
		vars->sprites.portal_1 = vars->animations.portal_1;
}