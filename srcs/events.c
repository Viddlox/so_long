/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 23:54:57 by micheng           #+#    #+#             */
/*   Updated: 2023/07/29 17:38:15 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	update_game_state(t_vars *vars)
{
	init_pos_list(&vars->head_pos, vars);
	init_parent_list(&vars->head_parent, vars);
	init_enemy(vars);
	free_lists(vars);
}

void	render_game(t_vars *vars)
{
	static int	count = 0;

	count++;
	if (count >= 100)
	{
		if (vars->en_count > 0)
			update_game_state(vars);
		count = 0;
	}
	render_sprites(vars);
}

void	game_loop(t_vars *vars)
{
	mlx_hook(vars->render.win, 2, (1L << 0), keypress, vars);
	mlx_hook(vars->render.win, 17, 0L, dest_win, vars);
	mlx_loop_hook(vars->render.mlx, (int (*)(void *))render_game, vars);
	mlx_loop(vars->render.mlx);
}
