/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_init_extras_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 23:42:37 by micheng           #+#    #+#             */
/*   Updated: 2023/08/07 23:44:59 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	portal_anim_init(t_vars *vars)
{
	int	x;
	int	y;
	vars->animations.portal_1 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/portal_1.xpm", &x, &y);
	vars->animations.portal_2 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/portal_2.xpm", &x, &y);
	vars->animations.portal_3 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/portal_3.xpm", &x, &y);
	vars->animations.portal_4 = mlx_xpm_file_to_image(vars->render.mlx,
			"assets/portal_4.xpm", &x, &y);
}