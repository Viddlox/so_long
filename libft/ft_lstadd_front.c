/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:45:27 by micheng           #+#    #+#             */
/*   Updated: 2023/05/06 23:05:35 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
/*
int	main(void)
{
	int	array[3] = {1, 2, 3};
	t_list *list = NULL;
	int	i = -1;
	while (++i < 3)
		ft_lstadd_front(&list, &array[i]);
	t_list *current = list;
	while (current != NULL)
	{
		printf("%d\n", *((int *)(current->content)));
		current = current->next;
	}
}

void	display(t_list *n)
{
	while (n != NULL)
	{
		printf("%d\n",*(int *)(n->content));
		n = n->next;
	}
}

int	main(void)
{
	t_list	node1;
	int a = 30;
	int *ptr1 = malloc(sizeof(int));
	*ptr1 = a;
	node1.content = ptr1;
	node1.next = NULL;

	t_list	node2;
	int b = 20;
	int *ptr2 = malloc(sizeof(int));
	*ptr2 = b;
	node2.content = ptr2;
	node2.next = NULL;

	ft_lstadd_front(&node1, &node2);
	display(&node1);
	return (0);
}
*/