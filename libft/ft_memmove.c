/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 01:00:18 by mcheng            #+#    #+#             */
/*   Updated: 2023/05/06 23:18:58 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	size_t	len_temp;
	char	*dest_temp;
	char	*src_temp;

	dest_temp = (char *)dst;
	src_temp = (char *)src;
	if (!dst && !src)
		return (0);
	else if (dest_temp < src_temp)
	{
		i = -1;
		while (++i < len)
			dest_temp[i] = src_temp[i];
	}
	else
	{
		len_temp = len;
		while (len_temp-- > 0)
			dest_temp[len_temp] = src_temp[len_temp];
	}
	return (dst);
}
