/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:52:44 by micheng           #+#    #+#             */
/*   Updated: 2023/08/07 10:55:36 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_win(char **map, t_vars *vars)
{
	ft_putstr_fd("You win!", 1);
	free_map(map, vars);
	if (vars->en_count > 0)
		free_lists(vars);
	mlx_destroy_image(vars->render.mlx, vars->game.step_img);
	ft_clear_tracked_data(&vars->head_tracker);
	exit (0);
}

void	print_lose(char **map, t_vars *vars)
{
	ft_putstr_fd("You lose!", 1);
	free_map(map, vars);
	if (vars->en_count > 0)
		free_lists(vars);
	mlx_destroy_image(vars->render.mlx, vars->game.step_img);
	ft_clear_tracked_data(&vars->head_tracker);
	exit (0);
}

void	print_icons(t_vars *vars)
{
	char	*step_count;
	char	*trap_count;
	char	*key_count;

	step_count = ft_itoa(vars->game.steps);
	trap_count = ft_itoa(vars->trap_count);
	key_count = ft_itoa(vars->k_left_count);

	mlx_string_put(vars->render.mlx,
		vars->render.win, 35, 5, 0x000000, "Steps: ");
	mlx_string_put(vars->render.mlx, vars->render.win, 100, 5, 0xFF0000, step_count);
	mlx_string_put(vars->render.mlx, vars->render.win, 35, 35, 0x000000, "x ");
	mlx_string_put(vars->render.mlx, vars->render.win, 50, 35, 0xFF0000, trap_count);
	mlx_string_put(vars->render.mlx, vars->render.win, 35, 60, 0x000000, "x ");
	mlx_string_put(vars->render.mlx, vars->render.win, 50, 60, 0xFF0000, key_count);
	mlx_put_image_to_window(vars->render.mlx, vars->render.win, vars->game.step_img, 15, 5);
	mlx_put_image_to_window(vars->render.mlx, vars->render.win, vars->game.trap_img, 15, 40);
	mlx_put_image_to_window(vars->render.mlx, vars->render.win, vars->game.key_img, 5, 65);
	mlx_put_image_to_window(vars->render.mlx, vars->render.win, vars->game.bomb_img, 195, 1);
	free(step_count);
	free(trap_count);
}

void	print_bomb_timer(t_vars *vars)
{
	char	*num;

	if (vars->time_bomb.timer <= 0)
		num = ft_itoa(0);
	else
		num = ft_itoa(vars->time_bomb.timer / 10000);
	mlx_string_put(vars->render.mlx, vars->render.win, 220, 1, 0x000000, ":");
	mlx_string_put(vars->render.mlx, vars->render.win, 230, 1, 0xFF0000, num);
	free(num);
}