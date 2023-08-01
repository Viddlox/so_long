/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bfs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 00:32:52 by micheng           #+#    #+#             */
/*   Updated: 2023/08/02 04:22:15 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	enqueue(t_queue_data *data, t_queue *step)
{
	t_queue	*new_node;
	t_queue	*current;

	new_node = malloc(sizeof(t_queue));
	if (!new_node)
	{
		fprintf(stderr, "Error: Memory allocation failed for new_node.\n");
		return ;
	}
	new_node->cur_x = step->cur_x;
	new_node->cur_y = step->cur_y;
	new_node->next = NULL;
	if (data->head == NULL)
		data->head = new_node;
	else
	{
		current = data->head;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
}

static void	add_parent(t_queue *data, t_vars *vars)
{
	t_parent	*current;
	t_parent	*temp;

	current = malloc(sizeof(t_parent));
	if (!current)
	{
		fprintf(stderr, "Error: Memory allocation failed for pos.\n");
		return ;
	}
	current->parent_x = data->cur_x;
	current->parent_y = data->cur_y;
	current->next = NULL;
	if (vars->head_parent->head == NULL)
		vars->head_parent->head = current;
	else
	{
		temp = vars->head_parent->head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = current;
	}
}

t_queue	*dequeue(t_queue_data *data, t_vars *vars)
{
	t_queue	*dequeued_node;

	if (!data->head)
		return (NULL);
	dequeued_node = data->head;
	data->head = data->head->next;
	add_parent(dequeued_node, vars);
	dequeued_node->next = NULL;
	return (dequeued_node);
}

static void	explore_neighbors(t_vars *vars,
		t_queue *current_step, char **map)
{
	int		i;
	int		new_x;
	int		new_y;
	t_queue	*new_step;

	i = -1;
	while (++i < 4)
	{
		new_x = x_vectors(current_step->cur_x, i);
		new_y = y_vectors(current_step->cur_y, i);
		path_cost(vars, new_x, new_y);
		if (new_x >= 0 && new_x < vars->map_l
			&& new_y >= 0 && new_y < vars->map_h
			&& map[new_y][new_x] != 'V' && !is_obstacle(map[new_y][new_x]))
		{
			new_step = malloc(sizeof(t_queue));
			if (!new_step)
				return ;
			new_step->cur_x = new_x;
			new_step->cur_y = new_y;
			enqueue(vars->head_queue, new_step);
			map[new_y][new_x] = 'V';
		}
	}
}

int	bfs(t_vars *vars, t_queue *new_step)
{
	t_queue	*current_step;
	char	**map;
	int		i;

	i = -1;
	map = clone_map(vars);
	enqueue(vars->head_queue, new_step);
	while (get_queue_size(vars->head_queue) > 0)
	{
		current_step = dequeue(vars->head_queue, vars);
		if (current_step->cur_y == vars->pos.y &&
			current_step->cur_x == vars->pos.x)
		{
			free(current_step);
			free_map(map, vars);
			ft_clear_queue_data(&vars->head_queue);
			vars->head_queue = NULL;
			ft_printf("Target found.\n");
			return (1);
		}
		explore_neighbors(vars, current_step, map);
		free(current_step);
	}
	return (0);
}