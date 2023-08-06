/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 19:36:24 by micheng           #+#    #+#             */
/*   Updated: 2023/08/06 09:38:38 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_queue_list(t_queue_data **data, t_vars *vars)
{
	*data = malloc(sizeof(t_queue_data));
	if (*data)
		(*data)->head = NULL;
	else
	{
		fprintf(stderr, "Error: Memory allocation failed for data.\n");
		ft_lstclear((t_list **)vars->head_queue, &ft_del);
		return ;
	}
}

void	init_pos_list(t_pos_data **data, t_vars *vars)
{
	*data = malloc(sizeof(t_pos_data));
	if (*data)
		(*data)->head = NULL;
	else
	{
		fprintf(stderr, "Error: Memory allocation failed for data.\n");
		ft_lstclear((t_list **)vars->head_pos, &ft_del);
		return ;
	}
}

void	init_parent_list(t_parent_data **data, t_vars *vars)
{
	*data = malloc(sizeof(t_parent_data));
	if (*data)
		(*data)->head = NULL;
	else
	{
		fprintf(stderr, "Error: Memory allocation failed for data.\n");
		ft_lstclear((t_list **)vars->head_parent, &ft_del);
		return ;
	}
}

void	init_tracker_list(t_tracker_data **data, t_vars *vars)
{
	*data = malloc(sizeof(t_tracker_data));
	if (*data)
		(*data)->head = NULL;
	else
	{
		fprintf(stderr, "Error: Memory allocation failed for data.\n");
		ft_lstclear((t_list **)vars->head_tracker, &ft_del);
		return ;
	}
}

void	add_tracked_node(t_pos *data, t_vars *vars)
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
