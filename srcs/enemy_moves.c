/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 01:02:52 by micheng           #+#    #+#             */
/*   Updated: 2023/07/26 13:43:28 by micheng          ###   ########.fr       */
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

// void enemy_delay(t_vars *vars) 
// {
//     static int loop_counter = 0;
//     static int delay_threshold = 100000; // Adjust this value to control the delay

//     loop_counter++;
//     if (loop_counter >= delay_threshold) 
// 	{
// 		init_enemy(vars);
//         loop_counter = 0;
//         mlx_clear_window(vars->render.mlx, vars->render.win);
//     }
// }

static int	manhattan_distance(t_parent *current, t_parent *next)
{
	return (abs(current->parent_x - next->parent_x)
		+ abs(current->parent_y - next->parent_y));
}

void	enemy_path(t_vars *vars)
{
	t_parent	*current_parent;
	t_parent	*next_parent;

	current_parent = vars->head_parent->head;
	while (current_parent != NULL)
	{
		next_parent = vars->head_parent->head->next;
		while (next_parent != NULL)
		{
			printf("cur_parent: (%d, %d)\n", current_parent->parent_y, current_parent->parent_x);
			printf("next_parent: (%d, %d)\n", next_parent->parent_y, next_parent->parent_x);
			printf("man_dist: %d\n", manhattan_distance(current_parent, next_parent));
			if (manhattan_distance(current_parent, next_parent) == 1)
			{
				vars->map[current_parent->parent_y][current_parent->parent_x] = '0';
				vars->map[next_parent->parent_y][next_parent->parent_x] = 'X';
				vars->pos.x_en = current_parent->parent_x;
				vars->pos.y_en = current_parent->parent_y;
				printf("enemy pos: (%d, %d)\n", vars->pos.y_en, vars->pos.x_en);
				mlx_clear_window(vars->render.mlx, vars->render.win);
				if (vars->pos.x == vars->pos.x_en
					&& vars->pos.y == vars->pos.y_en)
					print_lose(vars->map);
			}
			next_parent = next_parent->next;
		}
		current_parent = current_parent->next;
	}
}
