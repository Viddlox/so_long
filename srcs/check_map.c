/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:24:52 by micheng           #+#    #+#             */
/*   Updated: 2023/08/07 12:00:04 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_walls(t_vars *vars)
{
	int		i;
	int		r_side;
	char	*buffer_top;
	char	*buffer_bottom;

	i = vars->map_h;
	buffer_top = vars->map[0];
	buffer_bottom = vars->map[--i];
	r_side = ft_strlen(vars->map[0]) - 1;
	while (i <= r_side)
	{
		if (buffer_top[i] != '1' || buffer_bottom[i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < vars->map_h)
	{
		buffer_top = vars->map[i++];
		if (buffer_top[0] != '1' || buffer_top[r_side] != '1')
			return (0);
	}
	return (1);
}

static void	item_update(t_vars *vars, char c)
{
	if (c == 'C')
		vars->c_count++;
	else if (c == 'P')
		vars->p_count++;
	else if (c == 'E')
		vars->e_count++;
	else if (c == 'X')
		vars->en_count++;
	else if (c == 'B')
		vars->b_count++;
	else if (c == 'K')
		vars->k_count++;
	else if (c == '1' || c == '0')
		return ;
	else
		vars->invalid_count++;
}

int	check_entities(t_vars *vars)
{
	int	x;
	int	y;

	y = -1;
	while (vars->map[++y])
	{
		x = -1;
		while (vars->map[y][++x])
		{
			if (vars->map[y][x] == 'B')
			{
				vars->time_bomb.x = x;
				vars->time_bomb.y = y;
			}
			item_update(vars, vars->map[y][x]);
		}
	}
	if (vars->invalid_count > 0)
		return (0);
	if (!(vars->c_count > 0 || vars->e_count == 1
		|| vars->p_count == 1 || vars->b_count <= 1))
		return (0);
	else if (vars->b_count > 1)
		return (0);
	else if (vars->b_count == 1 && vars->k_count < 1)
		return (0);
	return (1);
}

int	check_map(t_vars *vars)
{
	vars->p_count = 0;
	vars->e_count = 0;
	vars->c_count = 0;
	vars->en_count = 0;
	vars->invalid_count = 0;
	if (!check_entities(vars))
		return (0);
	if (!check_walls(vars))
		return (0);
	else if (!check_path(vars))
		return (0);
	return (1);
}
