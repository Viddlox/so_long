/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 03:39:07 by mcheng            #+#    #+#             */
/*   Updated: 2023/05/06 19:30:59 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	if (!s1 && !s2)
		return (0);
	if (n == 0)
		return (0);
	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	s1[] = "";
	char	s2[] = "";
	char	s3[] = "";
	char	s4[] = "";

	printf("%s \n", s1);
	printf("%s \n", s2);
	printf("Result 1: %d \n", memcmp(s1, s2, 3));
	printf("Result 2: %d \n", ft_memcmp(s3, s4, 3));
	return (0);
}
*/