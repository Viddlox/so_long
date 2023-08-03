/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 08:22:51 by micheng           #+#    #+#             */
/*   Updated: 2023/08/03 08:06:30 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	animation(t_vars *vars)
{
	vars->animations.frame_count++;

	if (vars->animations.frame_count >= 10)
	{
		mlx_clear_window(vars->render.mlx, vars->render.win);
		if (vars->sprites.player_1 == vars->animations.player_left_1)
			vars->sprites.player_1 = vars->animations.player_left_2;
		else if (vars->sprites.player_1 == vars->animations.player_left_2)
			vars->sprites.player_1 = vars->animations.player_left_3;
		else if (vars->sprites.player_1 == vars->animations.player_left_3)
			vars->sprites.player_1 = vars->animations.player_left_1;

		if (vars->sprites.player_1 == vars->animations.player_right_1)
			vars->sprites.player_1 = vars->animations.player_right_2;
		else if (vars->sprites.player_1 == vars->animations.player_right_2)
			vars->sprites.player_1 = vars->animations.player_right_3;
		else if (vars->sprites.player_1 == vars->animations.player_right_3)
			vars->sprites.player_1 = vars->animations.player_right_1;

		if (vars->sprites.collectible_1 == vars->animations.collectible_2)
			vars->sprites.collectible_1 = vars->animations.collectible_2;
		else if (vars->sprites.collectible_1 == vars->animations.collectible_2)
			vars->sprites.collectible_1 = vars->animations.collectible_3;
		else if (vars->sprites.collectible_1 == vars->animations.collectible_4)
			vars->sprites.collectible_1 = vars->sprites.collectible_1;

		vars->animations.frame_count = 0;
		render_sprites(vars);
	}

	return (0);
}
