/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 01:02:52 by micheng           #+#    #+#             */
/*   Updated: 2023/08/05 06:48:33 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_closer(t_vars *vars, t_parent *next)
{
	int	next_cost;
	int	current_cost;

	next_cost = manhattan_distance(vars, next->parent_x, next->parent_y);
	current_cost = manhattan_distance(vars, vars->pos.x_en, vars->pos.y_en);
	return (next_cost <= current_cost);
}

static int	is_not_visited(t_vars *vars, t_parent *next)
{
	t_tracker	*current;

	current = vars->head_tracker->head;
	while (current != NULL)
	{
		if (current->x == next->parent_x && current->y == next->parent_y)
			return (0);
		current = current->next;
	}
	return (1);
}

static void	enemy_animation_state(t_vars *vars,
	t_parent *current, t_parent *next)
{
	if ((next->parent_x > current->parent_x)
		&& next->parent_y == current->parent_y)
	{
		vars->sprites.enemy_1 = vars->animations.enemy_right_1;
		vars->enemy_animation_state = ENEMY_MOVE_RIGHT;
	}
	else if ((next->parent_x < current->parent_x)
		&& next->parent_y == current->parent_y)
	{
		vars->sprites.enemy_1 = vars->animations.enemy_left_1;
		vars->enemy_animation_state = ENEMY_MOVE_LEFT;
	}
	else if ((next->parent_y > current->parent_y)
		&& next->parent_x == current->parent_x)
	{
		vars->sprites.enemy_1 = vars->animations.enemy_down_1;
		vars->enemy_animation_state = ENEMY_MOVE_DOWN;
	}
	else if ((next->parent_y < current->parent_y)
		&& next->parent_x == current->parent_x)
	{
		vars->sprites.enemy_1 = vars->animations.enemy_up_1;
		vars->enemy_animation_state = ENEMY_MOVE_UP;
	}
	else
	{
		vars->sprites.enemy_1 = vars->animations.enemy_idle;
		vars->enemy_animation_state = ENEMY_TELEPORT;
	}
}

static void	move_enemy(t_vars *vars,
	t_parent *current_parent, t_parent *next_parent)
{
	vars->map[current_parent->parent_y][current_parent->parent_x] = '0';
	vars->map[next_parent->parent_y][next_parent->parent_x] = 'X';
	vars->pos.x_en = next_parent->parent_x;
	vars->pos.y_en = next_parent->parent_y;
	enemy_animation_state(vars, current_parent, next_parent);
}

void	enemy_path(t_vars *vars)
{
	t_parent	*current_parent;
	t_parent	*next_parent;

	current_parent = vars->head_parent->head;
	next_parent = current_parent->next;
	while (current_parent != NULL)
	{
		vars->pos.x_en = current_parent->parent_x;
		vars->pos.y_en = current_parent->parent_y;
		if (next_parent != NULL && is_not_visited(vars, next_parent)
			&& is_closer(vars, next_parent))
		{
			clear_tracker_nodes(vars);
			move_enemy(vars, current_parent, next_parent);
			current_parent = current_parent->next;
			if (vars->pos.x == vars->pos.x_en && vars->pos.y == vars->pos.y_en)
				print_lose(vars->map, vars);
			mlx_clear_window(vars->render.mlx, vars->render.win);
			return ;
		}
		else
			next_parent = next_parent->next;
	}
}

