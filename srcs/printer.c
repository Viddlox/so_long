/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:52:44 by micheng           #+#    #+#             */
/*   Updated: 2023/07/31 14:48:19 by micheng          ###   ########.fr       */
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