/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_trap_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 08:14:42 by micheng           #+#    #+#             */
/*   Updated: 2023/08/06 08:32:01 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_clear_trapped_data(t_trap_data **data)
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

void	init_trapped_list(t_trap_data **data, t_vars *vars)
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

void	add_trapped_node(t_parent *data, t_vars *vars)
{
	t_trap	*current;
	t_trap	*temp;

	current = malloc(sizeof(t_trap));
	if (!current)
		return ;
	current->x = data->parent_x;
	current->y = data->parent_y;
	current->enemy_trapped = 1;
	current->enemy_trapped_count = 5;
	current->next = NULL;
	if (vars->head_trap->head == NULL)
		vars->head_trap->head = current;
	else
	{
		temp = vars->head_trap->head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = current;
	}
}