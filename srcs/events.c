/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 23:54:57 by micheng           #+#    #+#             */
/*   Updated: 2023/07/24 23:10:47 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_win(char **map)
{
	ft_putstr_fd("You win!", 1);
	free_map(map);
	exit (0);
}

void	print_lose(char **map)
{
	ft_putstr_fd("You lose!", 1);
	free_map(map);
	exit (0);
}

// void	update_game_state(t_vars *vars)
// {
	
// }
