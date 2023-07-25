// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   list_init.c                                        :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/07/23 19:36:24 by micheng           #+#    #+#             */
// /*   Updated: 2023/07/24 17:09:32 by micheng          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "so_long.h"

// void	init_parent_list(t_parent_data **data, t_vars *vars)
// {
// 	*data = malloc(sizeof(t_parent_data));
// 	if (*data)
// 		(*data)->head = NULL;
// 	else
// 	{
// 		fprintf(stderr, "Error: Memory allocation failed for data.\n");
// 		ft_lstclear((t_list **)vars->head_parent, &ft_del);
// 		return ;
// 	}
// }

// void	init_queue_list(t_queue_data **data, t_vars *vars)
// {
// 	*data = malloc(sizeof(t_queue_data));
// 	if (*data)
// 		(*data)->head = NULL;
// 	else
// 	{
// 		fprintf(stderr, "Error: Memory allocation failed for data.\n");
// 		ft_lstclear((t_list **)vars->head_queue, &ft_del);
// 		return ;
// 	}
// }

// void	init_pos_list(t_pos_data **data, t_vars *vars)
// {
// 	*data = malloc(sizeof(t_pos_data));
// 	if (*data)
// 		(*data)->head = NULL;
// 	else
// 	{
// 		fprintf(stderr, "Error: Memory allocation failed for data.\n");
// 		ft_lstclear((t_list **)vars->head_pos, &ft_del);
// 		return ;
// 	}
// }

// void	print_parent_list(t_parent *head)
// {
// 	t_parent *current = head;

// 	while (current != NULL)
// 	{
// 		printf("Parent: (%d, %d)\n", current->parent_y, current->parent_x);
// 		current = current->next;
// 	}
// }