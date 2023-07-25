/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:41:08 by mcheng            #+#    #+#             */
/*   Updated: 2023/05/07 18:08:30 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (0);
		s++;
	}
	return ((char *)s);
}

/*
int	main(void)
{
	char	str[] = "Hello";
	char	c = 'o';
	char	str1[] = "Hello";
	char	c1 = 'o';
	printf("%s\n", strchr(str, c));
	printf("%s\n", ft_strchr(str1, c1));
	return (0);
}
*/