/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:50:25 by micheng           #+#    #+#             */
/*   Updated: 2023/08/05 06:39:14 by micheng          ###   ########.fr       */
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
	exit(0);
}

int	keypress(int code, t_vars *vars)
{
	if (code == 13 || code == 126)
		move_up(vars);
	else if (code == 0 || code == 123)
		move_left(vars);
	else if (code == 1 || code == 125)
		move_down(vars);
	else if (code == 2 || code == 124)
		move_right(vars);
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
	vars.animations.en_speed = 0;
	if (check_file(ac, av, &vars) && ac == 2)
	{
		vars.game.steps = 0;
		vars.render.mlx = mlx_init();
		vars.render.win = mlx_new_window(vars.render.mlx,
				vars.map_l * 32, vars.map_h * 32, "so_long");
		init_sprites(&vars);
		render_sprites(&vars);
		init_tracker_list(&vars.head_tracker, &vars);
		mlx_hook(vars.render.win, 2, (1L << 0), keypress, &vars);
		mlx_hook(vars.render.win, 17, 0L, dest_win, &vars);
		mlx_loop_hook(vars.render.mlx, animation, &vars);
		mlx_loop(vars.render.mlx);
		// system("leaks -q so_long");
	}
	else
		ft_printf("Error: Map is invalid or not found.\n");
	return (0);
}
