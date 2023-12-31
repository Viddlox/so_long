/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 23:43:05 by micheng           #+#    #+#             */
/*   Updated: 2023/08/05 12:00:16 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_queue_size(t_queue_data *head)
{
	int		count;
	t_queue	*current;

	count = 0;
	current = head->head;

	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}

void	ft_clear_parent_data(t_parent_data **data)
{
	t_parent	*current;
	t_parent	*temp;

	if (!data || !*data)
		return ;
	current = (*data)->head;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	free(*data);
	*data = NULL;
}

void	ft_clear_queue_data(t_queue_data **data)
{
	t_queue	*current;
	t_queue	*temp;

	if (!data || !*data)
		return ;
	current = (*data)->head;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	free(*data);
	*data = NULL;
}

void	ft_clear_pos_data(t_pos_data **data)
{
	t_pos	*current;
	t_pos	*temp;

	if (!data || !*data)
		return ;
	current = (*data)->head;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	free(*data);
	*data = NULL;
}

void	ft_clear_tracked_data(t_tracker_data **data)
{
	t_tracker	*current;
	t_tracker	*temp;

	if (!data || !*data)
		return ;
	current = (*data)->head;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	free(*data);
	*data = NULL;
}
