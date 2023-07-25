/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 02:07:08 by mcheng            #+#    #+#             */
/*   Updated: 2023/05/06 19:36:26 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((unsigned char *)&str[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	s[] = "hello world";
	char	*ptr;
	char	s1[] = "hello world";
	char	*ptr1;

	ptr = memchr(s, 'o', strlen(s));
	ptr1 = ft_memchr(s1, 'o', strlen(s));
	if (ptr != NULL)
	{
		printf ("memchr: char found at pos %ld.\n", ptr - s);
		printf ("memchr: char found: %s\n", ptr);
	}
	else
		printf ("memchr: char not found\n");
	if (ptr1 != NULL)
	{
		printf ("ft_memchr: char found at pos %ld.\n", ptr1 - s1);
		printf ("ft_memchr: char found: %s\n", ptr1);
	}
	else
		printf ("ft_memchr: char not found\n");
	return (0);
}
*/