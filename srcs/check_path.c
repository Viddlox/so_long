/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 01:17:13 by micheng           #+#    #+#             */
/*   Updated: 2023/07/22 22:45:23 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**clone_map(t_vars *vars)
{
	char	**map_clone;
	int		i;

	map_clone = (char **) malloc (vars->map_h * sizeof(char *));
	if (map_clone == NULL)
		return (NULL);
	i = 0;
	while (i < vars->map_h)
	{
		map_clone[i] = ft_strdup(vars->map[i]);
		if (map_clone[i] == NULL)
		{
			while (++i < vars->map_h)
				free_map(&map_clone[i]);
			free(map_clone);
		}
		i++;
	}
	return (map_clone);
}

void	find_player(t_vars *vars)
{
	int	x;
	int	y;

	y = -1;
	while (++y < vars->map_h)
	{
		x = -1;
		while (++x < vars->map_l)
		{
			if (vars->map[y][x] == 'P')
			{
				vars->pos.x = x;
				vars->pos.y = y;
			}
		}
	}
}

int	path_algo(char **map, int x, int y, t_vars *vars)
{
	if (map[y][x] == 'E')
		return (1);
	map[y][x] = 'V';
	if (x > 0 && map[y][x - 1] != 'V' && map[y][x - 1] != '1')
	{
		if (path_algo(map, x - 1, y, vars) == 1)
			return (1);
	}
	if (x < vars->map_l - 1 && map[y][x + 1] != 'V' && map[y][x + 1] != '1')
	{
		if (path_algo(map, x + 1, y, vars) == 1)
			return (1);
	}
	if (y > 0 && map[y - 1][x] != 'V' && map[y - 1][x] != '1')
	{
		if (path_algo(map, x, y - 1, vars) == 1)
			return (1);
	}
	if (y < vars->map_h - 1 && map[y + 1][x] != 'V' && map[y + 1][x] != '1')
	{
		if (path_algo(map, x, y + 1, vars) == 1)
			return (1);
	}
	return (0);
}

int	check_path(t_vars *vars)
{
	char	**map_clone;
	int		i;

	find_player(vars);
	map_clone = clone_map(vars);
	if (!path_algo(map_clone, vars->pos.x, vars->pos.y, vars))
	{
		ft_printf("No valid path found.\n");
		return (0);
	}
	i = 0;
	while (++i < vars->map_h)
		free(map_clone[i]);
	free(map_clone);
	return (1);
}
