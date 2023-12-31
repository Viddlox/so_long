/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 06:24:21 by micheng           #+#    #+#             */
/*   Updated: 2023/08/08 04:54:59 by micheng          ###   ########.fr       */
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

int	is_obstacle(char c)
{
	if (c == '1' || c == 'E' || c == 'C'
		|| c == 'X' || c == 'D' || c == 'Z' 
		|| c == 'B' || c == 'K' || c == 'O' || c == 'U')
		return (1);
	return (0);
}

int	manhattan_distance(t_vars *vars, int x, int y)
{
	return (abs(x - vars->pos.x) + abs(y - vars->pos.y));
}

void	clear_tracker_nodes(t_vars *vars)
{
	t_tracker	*current_tracker;
	t_tracker	*temp;

	current_tracker = vars->head_tracker->head;
	while (current_tracker != NULL && current_tracker->next != NULL)
	{
		temp = current_tracker;
		current_tracker = current_tracker->next;
		free(temp);
	}
	vars->head_tracker->head = current_tracker;
}
