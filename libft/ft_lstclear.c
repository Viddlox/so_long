/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:19:51 by micheng           #+#    #+#             */
/*   Updated: 2023/08/02 02:02:07 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (*lst != NULL)
	{
		temp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}

// void	ft_del(void *content)
// {
// 	free(content);
// }
/*
int	main(void)
{
	t_list	*node = malloc(sizeof(t_list));
	t_list	*node1 = malloc(sizeof(t_list));
	int		a = 1;
	node->content = malloc(sizeof(int));
	*(int *)(node->content) = a;
	node->next = node1;

	int		b = 2;
	node1->content = malloc(sizeof(int));
	*(int *)(node1->content) = b;
	node1->next = NULL;

	printf("Before del:\n");
	t_list	*temp = node;
	while (temp)
	{
		printf("%d ", *(int *)temp->content);
		temp = temp->next;
	}
	printf("\n");
	ft_lstclear(&node, &ft_del);

	printf("After del:\n");
	temp = node;
	while (temp)
	{
		printf("%d ", *(int *)temp->content);
		temp = temp->next;
	}
	printf("\n");
}
*/