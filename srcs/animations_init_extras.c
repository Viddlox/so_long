/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_init_extras.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 11:37:25 by micheng           #+#    #+#             */
/*   Updated: 2023/08/07 06:28:33 by micheng          ###   ########.fr       */
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