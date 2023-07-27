/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 23:54:57 by micheng           #+#    #+#             */
/*   Updated: 2023/07/27 16:31:42 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_win(char **map)
{
	ft_putstr_fd("You win!", 1);
	free_map(map);
	exit (0);
}

void	print_lose(char **map)
{
	ft_putstr_fd("You lose!", 1);
	free_map(map);
	exit (0);
}

static void	update_game_state(t_vars *vars)
{
	if (vars->pos.x == vars->pos.x_en
		&& vars->pos.y == vars->pos.y_en)
		print_lose(vars->map);
	init_enemy(vars);
	ft_clear_pos_data(&vars->head_pos);
	ft_clear_queue_data(&vars->head_queue);
	ft_clear_parent_data(&vars->head_parent);
	vars->head_parent = NULL;
	vars->head_pos = NULL;
	vars->head_queue = NULL;
}

void	render_game(t_vars *vars)
{
	mlx_clear_window(vars->render.mlx, vars->render.win);
	update_game_state(vars);
	render_sprites(vars);
}

void	game_loop(t_vars *vars)
{
	mlx_hook(vars->render.win, 2, (1L << 0), keypress, vars);
	mlx_hook(vars->render.win, 17, 0L, dest_win, vars);
	mlx_loop_hook(vars->render.mlx, (int (*)(void *))render_game, vars);
	mlx_loop(vars->render.mlx);
}
