/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:45:42 by mcheng            #+#    #+#             */
/*   Updated: 2023/05/06 23:47:38 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;
	size_t	i;

	if (dstsize == 0)
		return (ft_strlen(src));
	srcsize = ft_strlen(src);
	i = 0;
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srcsize);
}
/*
int main(void)
{
    char src[] = "ABCD";
    char dst[5];

    size_t ret1 = ft_strlcpy(dst, src, sizeof(dst));
    size_t ret2 = strlcpy(dst, src, sizeof(dst));

    printf("ft_strlcpy: dst = \"%s\", ret = %zu\n", dst, ret1);
    printf("strlcpy: dst = \"%s\", ret = %zu\n", dst, ret2);

    return 0;
}
*/