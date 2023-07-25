/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheng < micheng@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:05:45 by mcheng            #+#    #+#             */
/*   Updated: 2023/03/25 17:23:49 by mcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = s;
	while (n--)
	{
		ptr[i] = 0;
		i++;
	}
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	str[10] = "hello";
	char	str1[10] = "hello";
	int		i;

	bzero(str, sizeof(str));
	if (strcmp(str, "") == 0)
		printf("test str has been zeroed out.\n");
	else
		printf("test str has not been zeroed out.\n");
	ft_bzero(str1, sizeof(str1));
	if (strcmp(str1, "") == 0)
		printf("str has been zeroed out.\n");
	else
		printf("str has not been zeroed out.\n");
	return (0);
}
*/