/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_init_extras.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 11:37:25 by micheng           #+#    #+#             */
/*   Updated: 2023/08/07 10:34:19 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	bomb_anim_init(t_vars *vars)
{
	int	x;
	int	y;
	vars->animations.bomb_1 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/bomb_1.xpm", &x, &y);
	vars->animations.bomb_2 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/bomb_2.xpm", &x, &y);
	vars->animations.bomb_3 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/bomb_3.xpm", &x, &y);
	vars->animations.bomb_4 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/bomb_4.xpm", &x, &y);
}

void	trap_anim_init(t_vars *vars)
{
	int	x;
	int	y;
	vars->animations.trap_1 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/trap_1.xpm", &x, &y);
	vars->animations.trap_2 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/trap_2.xpm", &x, &y);
	vars->animations.trap_3 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/trap_3.xpm", &x, &y);
	vars->animations.trap_4 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/trap_4.xpm", &x, &y);
}

void	key_anim_init(t_vars *vars)
{
	int	x;
	int	y;
	vars->animations.key_1 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/key_1.xpm", &x, &y);
	vars->animations.key_2 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/key_2.xpm", &x, &y);
	vars->animations.key_3 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/key_3.xpm", &x, &y);
	vars->animations.use_key_1 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/use_key_1.xpm", &x, &y);
	vars->animations.use_key_2 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/use_key_2.xpm", &x, &y);
}

void	explosion_anim_init(t_vars *vars)
{
	int	x;
	int	y;

	vars->animations.explosion_1 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/explosion_1.xpm", &x, &y);
	vars->animations.explosion_2 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/explosion_2.xpm", &x, &y);
	vars->animations.explosion_3 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/explosion_3.xpm", &x, &y);
	vars->animations.explosion_4 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/explosion_4.xpm", &x, &y);
	vars->animations.explosion_5 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/explosion_5.xpm", &x, &y);
	vars->animations.explosion_6 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/explosion_6.xpm", &x, &y);
	vars->animations.explosion_7 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/explosion_7.xpm", &x, &y);
	vars->animations.explosion_8 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/explosion_8.xpm", &x, &y);
	vars->animations.explosion_9 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/explosion_9.xpm", &x, &y);
	vars->animations.explosion_10 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/explosion_10.xpm", &x, &y);
	vars->animations.explosion_11 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/explosion_11.xpm", &x, &y);	
}

void	fire_anim_init(t_vars *vars)
{
	int	x;
	int	y;

	vars->animations.fire_1 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/fire_1.xpm", &x, &y);
	vars->animations.fire_2 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/fire_2.xpm", &x, &y);
	vars->animations.fire_3 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/fire_3.xpm", &x, &y);
	vars->animations.fire_4 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/fire_4.xpm", &x, &y);
	vars->animations.fire_5 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/fire_5.xpm", &x, &y);
	vars->animations.fire_6 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/fire_6.xpm", &x, &y);
	vars->animations.fire_7 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/fire_7.xpm", &x, &y);
	vars->animations.fire_8 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/fire_8.xpm", &x, &y);
}
