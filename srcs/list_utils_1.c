/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 19:36:24 by micheng           #+#    #+#             */
/*   Updated: 2023/08/02 04:23:28 by micheng          ###   ########.fr       */
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

void	free_lists(t_vars *vars)
{
	ft_clear_pos_data(&vars->head_pos);
	ft_clear_queue_data(&vars->head_queue);
	ft_clear_parent_data(&vars->head_parent);
	ft_clear_path_cost_data(&vars->head_path_cost);
	vars->head_pos = NULL;
	vars->head_queue = NULL;
	vars->head_parent = NULL;
	vars->head_path_cost = NULL;
}
