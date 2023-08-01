/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:42:57 by micheng           #+#    #+#             */
/*   Updated: 2023/08/02 02:02:53 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

// void	ft_del(void *content)
// {
// 	free(content);
// }
/*
int	main(void)
{
	t_list	*node = malloc(sizeof(t_list));
	int		a = 1;
	node->content = malloc(sizeof(int));
	*(int *)(node->content) = a;
	node->next = NULL;
	printf("%p Memory before free:\n", node->content);
	ft_lstdelone(node, &ft_del);
	printf("%p Memory after free:\n", node->content);
	return (0);
}
*/