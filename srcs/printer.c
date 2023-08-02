/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:52:44 by micheng           #+#    #+#             */
/*   Updated: 2023/08/02 07:49:07 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_win(char **map, t_vars *vars)
{
	ft_putstr_fd("You win!", 1);
	free_map(map, vars);
	exit (0);
}

void	print_lose(char **map, t_vars *vars)
{
	ft_putstr_fd("You lose!", 1);
	free_map(map, vars);
	exit (0);
}

void	print_parent_list(t_parent *head)
{
	t_parent	*current;

	current = head;
	while (current != NULL)
	{
		printf("Parent: (%d, %d)\n", current->parent_y, current->parent_x);
		current = current->next;
	}
}

void print_tracker_list(t_tracker *head_tracker)
{
    t_tracker *current = head_tracker;
    printf("Tracker List: ");
    while (current != NULL)
    {
        printf("(%d, %d) -> ", current->x, current->y);
        current = current->next;
    }
    printf("NULL\n");
}

void print_enemy_coordinates(t_pos *head)
{
    t_pos *current = head;

    while (current != NULL)
    {
        printf("Enemy Coordinate: (%d, %d)\n", current->x_en, current->y_en);
        current = current->next;
    }
}