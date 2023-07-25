/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 00:21:05 by mcheng            #+#    #+#             */
/*   Updated: 2023/05/07 20:05:47 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*src_temp;
	char	*dest_temp;

	i = -1;
	src_temp = (char *)src;
	dest_temp = (char *)dst;
	if (!dst && !src)
		return (0);
	while (++i < n)
		dest_temp[i] = src_temp[i];
	return (dst);
}
