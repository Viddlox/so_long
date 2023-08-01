/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 01:02:52 by micheng           #+#    #+#             */
/*   Updated: 2023/08/02 02:26:59 by micheng          ###   ########.fr       */
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

int	is_obstacle(char c)
{
	if (c == '1' || c == 'E' || c == 'C')
		return (1);
	return (0);
}

static int	is_visited(t_vars *vars, t_parent *next)
{
	t_tracker	*current;

	current = vars->head_tracker->head;
	while (current != NULL)
	{
		if (current->x == next->parent_x && current->y == next->parent_y)
			return (0);
		current = current->next;
	}
	return (1);
}

void	enemy_path(t_vars *vars)
{
	t_parent	*current_parent;
	t_parent	*next_parent;
	t_tracker	*current_tracker;
	t_tracker	*temp;

	current_parent = vars->head_parent->head;
	next_parent = current_parent->next;
	print_parent_list(vars->head_parent->head);
	print_tracker_list(vars->head_tracker->head);
	while (current_parent != NULL)
	{
		if (next_parent != NULL && is_visited(vars, next_parent))
		{
			vars->map[current_parent->parent_y][current_parent->parent_x] = '0';
			vars->map[next_parent->parent_y][next_parent->parent_x] = 'X';
			vars->pos.x_en = next_parent->parent_x;
			vars->pos.y_en = next_parent->parent_y;
			current_tracker = vars->head_tracker->head;
			while (current_tracker != NULL && current_tracker->next != NULL)
			{
				temp = current_tracker;
				current_tracker = current_tracker->next;
				free(temp);
			}
			vars->head_tracker->head = current_tracker;
			current_parent = current_parent->next;
			if (vars->pos.x == vars->pos.x_en && vars->pos.y == vars->pos.y_en)
				print_lose(vars->map, vars);
			mlx_clear_window(vars->render.mlx, vars->render.win);
			return ;
		}
		else
			next_parent = next_parent->next;
	}
}

