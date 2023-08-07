/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   icons.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 01:18:15 by micheng           #+#    #+#             */
/*   Updated: 2023/08/07 10:50:31 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_icons(t_vars *vars)
{
	int	x;
	int	y;

	vars->game.step_img = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/step_img.xpm", &x, &y);
	vars->game.trap_img = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/trap_img.xpm", &x, &y);
	vars->game.bomb_img = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/bomb_img.xpm", &x, &y);
	vars->game.key_img = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/key_img.xpm", &x, &y);
}
