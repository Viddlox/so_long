/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:57:17 by mcheng            #+#    #+#             */
/*   Updated: 2023/05/06 22:18:59 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_assign_num(char *str, long n, int i)
{
	str [i] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
		while (--i != 0)
		{
			str[i] = n % 10 + '0';
			n /= 10;
		}
	}
	while (--i >= 0)
	{
		str[i] = n % 10 + '0';
		n /= 10;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;
	long	temp;

	temp = n;
	i = 0;
	if (n <= 0)
		i++;
	while (temp != 0)
	{
		temp /= 10;
		i++;
	}
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	temp = n;
	return (ft_assign_num(str, temp, i));
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_itoa(-INT32_MAX));
}
*/