/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:03:14 by mcheng            #+#    #+#             */
/*   Updated: 2023/07/22 22:49:00 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (to_find[i] == '\0')
		return ((char *)str);
	if (n == 0)
		return (0);
	if (n > (unsigned int)ft_strlen((str)))
		n = ft_strlen(str);
	while (str[i] && i < n)
	{
		j = 0;
		while (to_find[j] && to_find[j] == str[i + j] && i + j < n)
			j++;
		if (to_find[j] == '\0')
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[100] = "Big Chungus";
	char	to_find[100] = "Chungus";
	char	str1[100] = "Big Chungus";
	char	to_find1[100] = "Chungus";
	printf("%s \n", str);
	printf("%s \n", to_find);
	printf("Result 1: %s \n", strnstr(str, to_find, 20));
	printf("Result 2: %s \n", ft_strnstr(str1, to_find1, 20));
}
*/