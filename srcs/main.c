/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:50:25 by micheng           #+#    #+#             */
/*   Updated: 2023/08/06 09:15:41 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map, t_vars *vars)
{
	int	i;

	i = -1;
	if (!map)
		return ;
	while (++i < vars->map_h)
		free(map[i]);
	free(map);
}

int	dest_win(t_vars *vars)
{
	mlx_destroy_window(vars->render.mlx, vars->render.win);
	free_map(vars->map, vars);
	free(vars->render.mlx);
	if (vars->en_count > 0)
		free_lists(vars);
	ft_clear_trapped_data(&vars->head_trap);
	ft_clear_tracked_data(&vars->head_tracker);
	exit(0);
}

int	keypress(int code, t_vars *vars)
{
	if (code == 13)
		move_up(vars);
	else if (code == 0)
		move_left(vars);
	else if (code == 1)
		move_down(vars);
	else if (code == 2)
		move_right(vars);
	else if (code == 3)
	{
		vars->play_dead = 1;
		vars->map[vars->pos.y][vars->pos.x] = 'D';
	}
	else if (code == 126 || code == 123 || code == 124 || code == 125)
		place_trap(vars, code);
	else if (code == 53)
		dest_win(vars);
	ft_printf ("Walked %i steps.\n", vars->game.steps);
	render_sprites(vars);
	return (0);
}

int	main(int ac, char **av)
{
	t_vars			vars;

	vars.animations.frame_count = 0;
	vars.play_dead = 0;
	vars.trap_count = 3;
	if (check_file(ac, av, &vars) && ac == 2)
	{
		vars.game.steps = 0;
		vars.render.mlx = mlx_init();
		vars.render.win = mlx_new_window(vars.render.mlx,
				vars.map_l * 32, vars.map_h * 32, "so_long");
		init_sprites(&vars);
		render_sprites(&vars);
		init_tracker_list(&vars.head_tracker, &vars);
		init_trapped_list(&vars.head_trap, &vars);
		mlx_hook(vars.render.win, 2, (1L << 0), keypress, &vars);
		mlx_hook(vars.render.win, 17, 0L, dest_win, &vars);
		mlx_loop_hook(vars.render.mlx, animation, &vars);
		mlx_loop(vars.render.mlx);
		system("leaks -q so_long");
	}
	else
		ft_printf("Error: Map is invalid or not found.\n");
	free_lists(&vars);
	ft_clear_trapped_data(&vars.head_trap);
	ft_clear_tracked_data(&vars.head_tracker);
	return (0);
}
