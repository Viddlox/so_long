/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:20:52 by micheng           #+#    #+#             */
/*   Updated: 2023/05/06 23:08:16 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	unsigned int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
/*
int	main(void)
{
	t_list *node1 = malloc(sizeof(t_list));
	node1->content = "node1";
	node1->next = NULL;

	t_list *node2 = malloc(sizeof(t_list));
	node2->content = "node2";
	node2->next = NULL;
	node1->next = node2;

	t_list *node3 = malloc(sizeof(t_list));
	node3->content = "node3";
	node3->next = NULL;
	node2->next = node3;
    node3->next = NULL;

	printf("list size:%d\n", ft_lstsize(node1));
	return (0);
}
*/