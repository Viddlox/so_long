/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 05:32:52 by micheng           #+#    #+#             */
/*   Updated: 2023/07/28 22:15:48 by micheng          ###   ########.fr       */
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

// static int	enemy_dfs_check(char **map, int x, int y, t_vars *vars)
// {
// 	if (map[y][x] == 'P')
// 		return (1);
// 	map[y][x] = 'V';
// 	if (x > 0 && map[y][x - 1] != 'V' && (!is_obstacle(map[y][x - 1])))
// 	{
// 		if (enemy_dfs_check(map, x - 1, y, vars) == 1)
// 			return (1);
// 	}
// 	if (x < vars->map_l - 1 && map[y][x + 1] != 'V'
// 		&& (!is_obstacle(map[y][x + 1])))
// 	{
// 		if (enemy_dfs_check(map, x + 1, y, vars) == 1)
// 			return (1);
// 	}
// 	if (y > 0 && map[y - 1][x] != 'V' && (!is_obstacle(map[y - 1][x])))
// 	{
// 		if (enemy_dfs_check(map, x, y - 1, vars) == 1)
// 			return (1);
// 	}
// 	if (y < vars->map_h - 1 && map[y + 1][x] != 'V'
// 		&& (!is_obstacle(map[y + 1][x])))
// 	{
// 		if (enemy_dfs_check(map, x, y + 1, vars) == 1)
// 			return (1);
// 	}
// 	return (0);
// }

// static int	enemy_valid_path(t_vars *vars, t_pos *current)
// {
// 	char	**map;
// 	int		i;

// 	i = 0;
// 	map = clone_map(vars);
// 	while (current != NULL)
// 	{
// 		if (!enemy_dfs_check(map, current->x_en, current->y_en, vars))
// 		{
// 			ft_printf("No valid enemy path.\n");
// 			free_map(map, vars);
// 			free_lists(vars);
// 			exit (0);
// 		}
// 		current = current->next;
// 	}
// 	free_map(map, vars);
// 	return (1);
// }

void	init_enemy(t_vars *vars)
{
	t_pos	*current;
	t_queue	*en_current_step;

	find_enemies(&(vars->head_pos->head), vars, 1, 1);
	current = vars->head_pos->head;
	// enemy_valid_path(vars, current);
	while (current != NULL)
	{
		init_queue_list(&vars->head_queue, vars);
		en_current_step = malloc(sizeof(t_queue));
		if (!en_current_step)
			return ;
		en_current_step->cur_y = current->y_en;
		en_current_step->cur_x = current->x_en;
		bfs(vars, en_current_step);
		// enemy_path(vars);
		free(en_current_step);
		ft_clear_queue_data(&vars->head_queue);
		ft_clear_parent_data(&vars->head_parent);
		current = current->next;
	}
}
