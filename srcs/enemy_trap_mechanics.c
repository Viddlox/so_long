/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_trap_mechanics.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 03:46:29 by micheng           #+#    #+#             */
/*   Updated: 2023/08/06 04:10:55 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_trapped_enemies_list(t_trap_data **data, t_vars *vars)
{
	*data = malloc(sizeof(t_trap_data));
	if (*data)
		(*data)->head = NULL;
	else
	{
		fprintf(stderr, "Error: Memory allocation failed for data.\n");
		ft_lstclear((t_list **)vars->head_trap, &ft_del);
		return ;
	}
}

void	ft_clear_trapped_list_data(t_trap_data **data)
{
	t_trap	*current;
	t_trap	*temp;

	if (!data || !*data)
		return ;
	current = (*data)->head;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	free(*data);
	*data = NULL;
}


static	void	add_tracked_node(t_pos *data, t_vars *vars)
{
	t_tracker	*current;
	t_tracker	*temp;

	current = malloc(sizeof(t_tracker));
	if (!current)
		return ;
	current->x = data->x_en;
	current->y = data->y_en;
	current->next = NULL;
	if (vars->head_tracker->head == NULL)
		vars->head_tracker->head = current;
	else
	{
		temp = vars->head_tracker->head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = current;
	}
}

void	enemy_trap_mechanics(t_vars *vars, t_parent *current, t_parent *next)
{
	vars->trapped_enemies->enemy_trapped = 1;
	vars->trapped_enemies.enemy_trapped_count = 5;
	vars->map[current_parent->parent_y][current_parent->parent_x] = '0';
	vars->map[next_parent->parent_y][next_parent->parent_x] = 'X';
	vars->pos.x_en = next_parent->parent_x;
	vars->pos.y_en = next_parent->parent_y;
	vars->trapped_enemies->x = next_parent->parent_x;
	vars->trapped_enemies->y = next_parent->parent_y;
}