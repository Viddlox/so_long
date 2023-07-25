// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   enemy_moves.c                                      :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/07/11 01:02:52 by micheng           #+#    #+#             */
// /*   Updated: 2023/07/25 15:03:49 by micheng          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "so_long.h"

// int	x_vectors(int x, int i)
// {
// 	if (i == 0)
// 		return (x - 1);
// 	else if (i == 1)
// 		return (x + 1);
// 	return (x);
// }

// int	y_vectors(int y, int i)
// {
// 	if (i == 2)
// 		return (y - 1);
// 	else if (i == 3)
// 		return (y + 1);
// 	return (y);
// }

// void	enemy_path(t_vars *vars)
// {
// 	int			dx;
// 	int			dy;
// 	t_parent	*current_parent;
// 	t_parent	*next_parent;

// //

// 	current_parent = vars->head_parent->head;
// 	while (current_parent != NULL)
// 	{
// 		next_parent = vars->head_parent->head->next;
// 		while (next_parent != NULL)
// 		{
// 			dx = abs(current_parent->parent_x - next_parent->parent_x);
// 			dy = abs(current_parent->parent_y - next_parent->parent_y);
// 			if (dx == 1 || dy == 1)
// 			{
// 				vars->map[current_parent->parent_y][current_parent->parent_x] = '0';
// 				vars->map[next_parent->parent_y][next_parent->parent_x] = 'X';
// 				// update_game_state(vars);
// 				render_sprites(vars);
// 				mlx_clear_window(vars->render.mlx, vars->render.win);
// 				if (vars->pos.x == vars->pos.x_en
// 					&& vars->pos.y == vars->pos.x_en)
// 					print_lose(vars->map);
// 			}
// 			next_parent = next_parent->next;
// 		}
// 		current_parent = current_parent->next;
// 	}
// }
