/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:40:14 by micheng           #+#    #+#             */
/*   Updated: 2023/05/04 16:10:37 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst == NULL)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}
/*
int	main(void)
{
	t_list	*list;
	t_list	*node;
	int		array[3] = {1, 2, 3};
	int		i;

	list = NULL;
	i = -1;
	while (++i < 3)
	{
		node = ft_lstnew(&array[i]);
		ft_lstadd_back(&list, node);
	}
	t_list	*current = list;
	while (current != NULL)
	{
		printf("%d\n", *((int *)(current->content)));
		current = current->next;
	}
}
*/
/*
void	display(t_list *n)
{
	while (n != NULL)
	{
		printf("%d\n",*(int *)n->content);
		n = n->next;
	}
}

int	main(void)
{
	t_list *node1 = malloc(sizeof(t_list));
	int a = 30;
	void *ptr = &a;
	node1->content = ptr;
	node1->next = NULL;

	t_list *node2 = malloc(sizeof(t_list));
	int	b = 20;
	void *ptr2 = &b;
	node2->content = ptr2;
	node2->next = NULL;
	node1->next = node2;

	t_list *node3 = malloc(sizeof(t_list));
	int	c = 10;
	void *ptr3 = &c;
	node3->content = ptr3;
	node3->next = NULL;
	node2->next = node3;
    node3->next = NULL;

	t_list *node4 = malloc(sizeof(t_list));
	int d = 40;
	void *ptr4 = &d;
	node4->content = ptr4;
	node4->next = NULL;
	ft_lstadd_back(&node1, node4);

	display(node1);
	return (0);
}
*/