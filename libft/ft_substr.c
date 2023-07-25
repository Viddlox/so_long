/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 22:06:40 by mcheng            #+#    #+#             */
/*   Updated: 2023/07/22 22:50:00 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;

	if (!s)
		return (0);
	if (len > (unsigned int)ft_strlen(s))
		len = ft_strlen(s) - start + 1;
	if (start >= (unsigned int)ft_strlen(s))
		len = 0;
	substr = malloc(len * sizeof(char) + 1);
	if (!substr)
		return (0);
	i = 0;
	while (i < len && s[start])
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}
/*
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (len > ft_strlen(s))
		len = ft_strlen(s) - start + 1;
	if (start >= ft_strlen(s))
		len = 0;
	if (len >= 0)
		substr = malloc(len * sizeof(char) + 1);
	else
		return (0);
	if (!substr)
		return (0);
	while (i < len && s[start])
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}
*/
/*
int	main(void)
{
	char 	str[] = "Hello";
	printf("%s", ft_substr(str, 0, 2));
	return (0);
}
*/
