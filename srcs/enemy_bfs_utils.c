/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bfs_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 02:44:48 by micheng           #+#    #+#             */
/*   Updated: 2023/08/02 04:24:00 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_path_cost_list(t_path_cost_data **data, t_vars *vars)
{
	*data = malloc(sizeof(t_path_cost_data));
	if (*data)
		(*data)->head = NULL;
	else
	{
		fprintf(stderr, "Error: Memory allocation failed for data.\n");
		ft_lstclear((t_list **)vars->head_tracker, &ft_del);
		return ;
	}
}

void	ft_clear_path_cost_data(t_path_cost_data **data)
{
	t_path_cost	*current;
	t_path_cost	*temp;

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

static int	manhattan_distance(t_vars *vars, int x, int y)
{

}

static void	add_path(void)
{
	
}

void	path_cost(t_vars *vars, int x, int y)
{
	
}