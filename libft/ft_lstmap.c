/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:04:04 by micheng           #+#    #+#             */
/*   Updated: 2023/05/04 23:59:30 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*new_list;

	new_list = NULL;
	if (!lst || !del || !f)
		return (0);
	while (lst != NULL)
	{
		temp = ft_lstnew(f(lst->content));
		if (temp == NULL)
		{
			ft_lstclear(&new_list, del);
			del(lst->content);
			free(lst);
			return (NULL);
		}
		ft_lstadd_back(&new_list, temp);
		lst = lst->next;
	}
	return (new_list);
}
/*
void	ft_add1(void *content)
{
	(*(int *)content) += 1;
}

void	ft_del(void *content)
{
	free(content);
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
	ft_lstmap(node1, &ft_add1, &ft_del);
	printf("After:\n");
	printf("%d | %d\n", *(int *)node1->content, *(int *)node2->content);
	return (0);
}
*/