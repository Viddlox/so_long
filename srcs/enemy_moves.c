/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 01:02:52 by micheng           #+#    #+#             */
/*   Updated: 2023/07/28 22:16:30 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	x_vectors(int x, int i)
{
	if (i == 0)
		return (x - 1);
	else if (i == 1)
		return (x + 1);
	return (x);
}

int	y_vectors(int y, int i)
{
	if (i == 2)
		return (y - 1);
	else if (i == 3)
		return (y + 1);
	return (y);
}

int	is_adjacent(int x1, int y1, int x2, int y2)
{
	int	dx;
	int	dy;

	dx = abs(x1 - x2);
	dy = abs(y1 - y2);
	return ((dx == 1 && dy == 0) || (dx == 0 && dy == 1));
}

// static int	manhattan_distance(t_vars *vars, t_parent *current, t_parent *next)
// {
// 	int	res;
// 	int	diff;
// 	int	adjust;
// 	int	temp_x;
// 	int	temp_y;

// 	if (vars->map[])
// 	res = (abs(vars->pos.x - current->parent_x)
// 			+ abs(vars->pos.y - current->parent_y));
// 	diff = (abs(vars->pos.x - next->parent_x)
// 			+ abs(vars->pos.y - next->parent_y));
// 	printf("temp: %d\n", diff);
// 	printf("res: %d\n", res);
// 	printf("current: %d, %d\n", current->parent_y, current->parent_x);
// 	printf("next: %d, %d\n", next->parent_y, next->parent_x);
// 	if (diff < res)
// 		return (1);
// 	return (0);
// }

// void	enemy_path(t_vars *vars)
// {
// 	t_parent	*current_parent;
// 	t_parent	*next_parent;

// 	current_parent = vars->head_parent->head;
// 	if (current_parent == NULL)
// 		return ;
// 	next_parent = vars->head_parent->head->next;
// 	print_parent_list(vars->head_parent->head);
// 	while (current_parent != NULL)
// 	{
// 		if (next_parent != NULL && (is_adjacent(current_parent->parent_x,
// 					current_parent->parent_y,
// 					next_parent->parent_x, next_parent->parent_y)
// 				&& manhattan_distance(vars, current_parent, next_parent)))
// 		{
// 			vars->map[current_parent->parent_y][current_parent->parent_x] = '0';
// 			vars->map[next_parent->parent_y][next_parent->parent_x] = 'X';
// 			vars->pos.x_en = next_parent->parent_x;
// 			vars->pos.y_en = next_parent->parent_y;
// 			current_parent = current_parent->next;
// 			if (vars->pos.x == vars->pos.x_en && vars->pos.y == vars->pos.y_en)
// 				print_lose(vars->map, vars);
// 			mlx_clear_window(vars->render.mlx, vars->render.win);
// 			return ;
// 		}
// 		else
// 			next_parent = next_parent->next;
// 	}
// }
