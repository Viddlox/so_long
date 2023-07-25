/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:16:02 by mcheng            #+#    #+#             */
/*   Updated: 2023/05/07 18:50:51 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			i;
	size_t			dst_len;
	size_t			src_len;

	i = 0;
	dst_len = 0;
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	if (size < 0)
		return (src_len + size);
	while (dst[dst_len] && dst_len < size)
		dst_len++;
	while (src[i] != '\0' && (i + dst_len < size - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (dst_len < size)
		dst[dst_len + i] = '\0';
	return (src_len + dst_len);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("%lu\n", strlcat("abc", "def", 3));
	printf("%zu\n", ft_strlcat("abc", "def", 3));
	return (0);
}
*/