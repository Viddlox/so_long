/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:06:00 by shechong          #+#    #+#             */
/*   Updated: 2023/08/08 21:09:17 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen_gnl(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
	}
	return (i);
}

char	*ft_strjoin_gnl(char *save, char *buf, int r)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = malloc(sizeof(char) * (ft_strlen_gnl(save) + r + 1));
	if (!res)
		return (NULL);
	if (save)
	{
		while (save[i])
		{
			res[i] = save[i];
			i++;
		}
		free(save);
	}
	while (j < r)
		res[i++] = buf[j++];
	res[i] = '\0';
	return (res);
}

int	ft_strchr_gnl(char *str, char c)
{
	int	i;

	i = 0;
	if (!str || !str[i])
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}