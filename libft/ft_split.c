/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:10:39 by mcheng            #+#    #+#             */
/*   Updated: 2023/07/31 17:07:13 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_separator(char str, char c)
{
	if (str == c)
		return (1);
	return (0);
}

static int	ft_count_words(char const *str, char c)
{
	int	i;
	int	word_count;

	i = 0;
	word_count = 0;
	while (str[i])
	{
		while (str[i] && ft_is_separator(str[i], c) == 1)
			i++;
		if (str[i])
			word_count++;
		while (str[i] && ft_is_separator(str[i], c) == 0)
			i++;
	}
	return (word_count);
}

static char	*ft_strdup2(char const *str, char c)
{
	int		i;
	char	*string;
	int		word_len;

	i = 0;
	word_len = 0;
	while (str[i] && ft_is_separator(str[i], c) == 0)
	{
		i++;
		word_len++;
	}
	string = malloc(sizeof(char) * (word_len + 1));
	if (!string)
		return (NULL);
	i = 0;
	while (i < word_len)
	{
		string[i] = str[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

char	**ft_split(char const *s, char c)
{
	char	**string;
	int		i;
	int		word_count;
	int		word;

	i = 0;
	word = 0;
	word_count = ft_count_words(&s[i], c);
	string = malloc(sizeof(char *) * (word_count + 1));
	if (!string)
		return (NULL);
	while (word < word_count)
	{
		while (ft_is_separator(s[i], c) == 1)
			i++;
		if (s[i])
		{
			string[word] = ft_strdup2(&s[i], c);
				word++;
			while (s[i] && ft_is_separator(s[i], c) == 0)
				i++;
		}
	}
	string[word] = NULL;
	return (string);
}

// #include <stdio.h>

// int main()
// {
// 	char s[] = "What is love baby don't hurt me       ";
// 	char c = ' ';
// 	int i = 0;
// 	char **strings;
// 	strings = ft_split(s, c);
// 	while (strings[i])
// 	{
// 		printf("%s | %p\n", strings[i], strings[i]);
// 		i++;
// 	}
// }
