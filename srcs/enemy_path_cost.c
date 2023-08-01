/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_path_cost.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 02:44:48 by micheng           #+#    #+#             */
/*   Updated: 2023/08/02 05:33:59 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	ft_clear_path_cost_data(t_path_cost_data **data)
// {
// 	t_path_cost	*current;
// 	t_path_cost	*temp;

// 	if (!data || !*data)
// 		return ;
// 	current = (*data)->head;
// 	while (current != NULL)
// 	{
// 		temp = current;
// 		current = current->next;
// 		free(temp);
// 	}
// 	free(*data);
// 	*data = NULL;
// }

int	manhattan_distance(t_vars *vars, int x, int y)
{
	int	dx;
	int	dy;

	dx = abs(x - vars->pos.x);
	dy = abs(y - vars->pos.y);
	return (dx + dy);
}

// void	add_path(t_queue *data, t_vars *vars, int cost)
// {
// 	t_path_cost	*current;
// 	t_path_cost	*temp;

// 	current = malloc(sizeof(t_parent));
// 	if (!current)
// 	{
// 		fprintf(stderr, "Error: Memory allocation failed for pos.\n");
// 		return ;
// 	}
// 	current->x = data->cur_x;
// 	current->y = data->cur_y;
// 	current->cost = cost;
// 	current->next = NULL;
// 	if (vars->head_parent->head == NULL)
// 		vars->head_parent->head = current;
// 	else
// 	{
// 		temp = vars->head_parent->head;
// 		while (temp->next != NULL)
// 			temp = temp->next;
// 		temp->next = current;
// 	}
// }