/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:40:57 by mcheng            #+#    #+#             */
/*   Updated: 2023/05/04 23:56:33 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;
	char	*s_temp;

	if (!s || !f)
		return (0);
	s_temp = (char *)s;
	str = ft_strdup(s_temp);
	if (!str)
		return (NULL);
	i = -1;
	while (s[++i])
		str[i] = f(i, str[i]);
	return (str);
}
/*
int	main(void)
{
	char	str[] = "HELLO WORLD";
	printf("%s", ft_strmapi(str, &ft_tolower));
	return (0);
}
*/
