/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:08:56 by micheng           #+#    #+#             */
/*   Updated: 2023/05/04 23:59:43 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;

	if (!lst)
		return ;
	while (lst != NULL)
	{
		temp = (lst)->next;
		f(lst->content);
		lst = temp;
	}
}
/*
void	ft_add1(void *content)
{
	(*(int *)content) += 1;
}

int	main(void)
{
	t_list	*node1 = malloc(sizeof(t_list));
	t_list	*node2 = malloc(sizeof(t_list));
	node1->content = malloc(sizeof(int));
	node2->content = malloc(sizeof(int));
	int a = 1;
	int	b = 2;
	*(int *)(node1->content) = a;
	node1->next = node2;
	*(int *)(node2->content) = b;
	node2->next = NULL;
	printf("Before:\n");
	printf("%d | %d\n", *(int *)node1->content, *(int *)node2->content);
	ft_lstiter(node1, &ft_add1);
	printf("After:\n");
	printf("%d | %d\n", *(int *)node1->content, *(int *)node2->content);
	return (0);
}
*/