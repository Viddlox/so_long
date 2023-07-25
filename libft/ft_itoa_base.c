/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:11:27 by micheng           #+#    #+#             */
/*   Updated: 2023/06/05 15:30:17 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_base_len(unsigned long long num, char *base)
{
	unsigned long long	base_len;
	size_t				len;

	len = 1;
	base_len = ft_strlen(base);
	while (num >= base_len)
	{
		num = num / base_len;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(unsigned long long num, char *base)
{
	int		len;
	int		base_len;
	char	*str;

	len = ft_base_len(num, base);
	base_len = ft_strlen(base);
	str = ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (len)
	{
		len -= 1;
		str[len] = base[num % base_len];
		num = num / base_len;
	}
	return (str);
}
