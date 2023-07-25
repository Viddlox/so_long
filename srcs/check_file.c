/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:55:22 by micheng           #+#    #+#             */
/*   Updated: 2023/07/22 22:47:11 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	map_size(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
			x++;
		y++;
	}
	if (y == x)
		return (0);
	vars->map_h = y;
	vars->map_l = x;
	return (1);
}

static int	read_map(char *map, t_vars *vars)
{
	int		fd;
	char	*line;
	char	*buffer;

	vars->map_h = 0;
	vars->map_l = 0;
	fd = open(map, O_RDONLY);
	line = ft_strdup("");
	while (line)
	{
		buffer = get_next_line(fd);
		if (buffer == NULL)
			break ;
		line = ft_strjoin(line, buffer);
		free(buffer);
	}
	vars->map = ft_split(line, '\n');
	free(line);
	if (!map_size(vars))
		return (0);
	close (fd);
	return (1);
}

static int	check_file_type(char *str)
{
	int		len;
	char	*filetype;

	len = ft_strlen (str);
	filetype = &str[(len - 4)];
	if (ft_strncmp (filetype, ".ber", 4) != 0)
	{
		ft_printf("Invalid \".ber\" file.");
		exit(0);
		return (0);
	}
	return (1);
}

int	check_file(int ac, char **av, t_vars *vars)
{
	if (ac == 2 && check_file_type(av[1]))
	{
		if (!read_map(av[1], vars))
			return (0);
		if (!check_map(vars))
			return (0);
	}
	return (1);
}
