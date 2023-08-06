/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:52:44 by micheng           #+#    #+#             */
/*   Updated: 2023/08/07 02:39:55 by micheng          ###   ########.fr       */
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

void	print_steps(t_vars *vars)
{
	char	*num;

	num = ft_itoa(vars->game.steps);
	mlx_string_put(vars->render.mlx,
		vars->render.win, 35, 10, 0x000000, "Steps: ");
	mlx_string_put(vars->render.mlx, vars->render.win, 100, 10, 0xFF0000, num);
	free(num);
}

void	print_trap_count(t_vars *vars)
{
	char	*num;

	num = ft_itoa(vars->trap_count);
	mlx_string_put(vars->render.mlx, vars->render.win, 35, 40, 0x000000, "x ");
	mlx_string_put(vars->render.mlx, vars->render.win, 50, 40, 0xFF0000, num);
	free(num);
}

// void	print_bomb_timer(t_vars *vars)
// {
// 	char	*num;

// 	num = ft_itoa(vars->trap_count);
// 	mlx_string_put(vars->render.mlx, vars->render.win, 60, 40, 0x000000, "x ");
// 	mlx_string_put(vars->render.mlx, vars->render.win, 80, 40, 0xFF0000, num);
// 	free(num);
// }