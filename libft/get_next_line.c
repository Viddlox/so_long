/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:05:47 by shechong          #+#    #+#             */
/*   Updated: 2023/08/08 21:09:22 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*free_and_return(void *var, void *ret)
{
	free(var);
	return (ret);
}

char	*ft_getline(char *save)
{
	char	*line;
	int		i;

	i = 0;
	if (!save || !save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i])
	{
		line[i] = save[i];
		i++;
		if (save[i - 1] == '\n')
			break ;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_strclean(char *static_buffer)
{
	char	*str;
	int		i;
	int		j;

	if (!static_buffer)
		return (NULL);
	i = 0;
	while (static_buffer[i] && static_buffer[i] != '\n')
		i++;
	if (!static_buffer[i])
	{
		free(static_buffer);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(static_buffer) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (static_buffer[i])
		str[j++] = static_buffer[i++];
	str[j] = '\0';
	return (free_and_return(static_buffer, str));
}

char	*get_next_line(int fd)
{
	char		*res;
	char		*buffer;
	static char	*temp_buffer;
	int			r;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	r = 1;
	while (!ft_strchr_gnl(temp_buffer, '\n') && r != 0)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r == -1)
			return (free_and_return(buffer, NULL));
		buffer[r] = '\0';
		temp_buffer = ft_strjoin_gnl(temp_buffer, buffer, r);
	}
	res = ft_getline(temp_buffer);
	temp_buffer = ft_strclean(temp_buffer);
	return (free_and_return(buffer, res));
}
