/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 01:02:52 by micheng           #+#    #+#             */
/*   Updated: 2023/07/30 17:11:45 by micheng          ###   ########.fr       */
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

void	enemy_path(t_vars *vars)
{
	t_parent	*current_parent;

	current_parent = vars->head_parent->head;
	while (current_parent != NULL)
	{
		vars->map[current_parent->parent_y][current_parent->parent_x] = '0';
		vars->pos.x_en = current_parent->parent_x;
		vars->pos.y_en = current_parent->parent_y;
		vars->map[current_parent->parent_y][current_parent->parent_x] = 'X';
		current_parent = current_parent->next;
		if (vars->pos.x == vars->pos.x_en && vars->pos.y == vars->pos.y_en)
			print_lose(vars->map, vars);
		mlx_clear_window(vars->render.mlx, vars->render.win);
	}
}