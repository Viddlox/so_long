/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 05:32:52 by micheng           #+#    #+#             */
/*   Updated: 2023/07/30 16:25:47 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_step(int cur_x, int cur_y,
	int *next_x, int *next_y, t_vars *vars)
{
	if (cur_y + 1 == vars->map_h)
	{
		*next_x = cur_x + 1;
		*next_y = 0;
	}
	else
	{
		*next_x = cur_x;
		*next_y = cur_y + 1;
	}
}

void	find_enemies(t_pos **head, t_vars *vars, int cur_y, int cur_x)
{
	t_pos	*new_pos;

	if (cur_x >= vars->map_l || cur_y >= vars->map_h)
		return ;
	if (vars->map[cur_y][cur_x] == 'X')
	{
		new_pos = malloc(sizeof(t_pos));
		if (!new_pos)
		{
			fprintf(stderr, "Error: Memory allocation failed for pos.\n");
			return ;
		}
		new_pos->x_en = cur_x;
		new_pos->y_en = cur_y;
		new_pos->next = *head;
		*head = new_pos;
	}
	check_step(cur_x, cur_y, &cur_x, &cur_y, vars);
	find_enemies(head, vars, cur_y, cur_x);
}

void	init_enemy(t_vars *vars)
{
	t_pos	*current;
	t_queue	*en_current_step;
	char	**map;

	find_enemies(&(vars->head_pos->head), vars, 1, 1);
	current = vars->head_pos->head;
	while (current != NULL)
	{
		map = clone_map(vars);
		init_queue_list(&vars->head_queue, vars);
		en_current_step = malloc(sizeof(t_queue));
		if (!en_current_step)
			return ;
		en_current_step->cur_y = current->y_en;
		en_current_step->cur_x = current->x_en;
		bfs(vars, en_current_step, map);
		print_parent_list(vars->head_parent->head);
		free_map(map, vars);
		enemy_path(vars);
		free(en_current_step);
		ft_clear_queue_data(&vars->head_queue);
		ft_clear_parent_data(&vars->head_parent);
		current = current->next;
	}
}
