/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 15:49:45 by maridos-          #+#    #+#             */
/*   Updated: 2026/09/23 10:15:29 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_closest_above(t_stack *a, int b_idx, int *size)
{
	t_stack	*current;
	int		min_bigger;
	int		target_pos;

	current = a;
	min_bigger = 2147483647;
	target_pos = -1;
	*size = 0;
	while (current)
	{
		if (current->index > b_idx && current->index < min_bigger)
		{
			min_bigger = current->index;
			target_pos = *size;
		}
		current = current->next;
		(*size)++;
		if (current == a)
			break ;
	}
	return (target_pos);
}

int	ft_find_min_pos(t_stack *stack, int size)
{
	t_stack	*current;
	int		min_index;
	int		min_pos;
	int		i;

	if (!stack || size <= 0)
		return (0);
	current = stack;
	min_index = current->index;
	min_pos = 0;
	i = 0;
	while (i < size)
	{
		if (current->index < min_index)
		{
			min_index = current->index;
			min_pos = i;
		}
		current = current->next;
		i++;
	}
	return (min_pos);
}

int	get_target_for_b(t_stacks *stacks)
{
	int	target_pos;
	int	size;

	if (!stacks->a || !stacks->b)
		return (0);
	target_pos = find_closest_above(stacks->a, stacks->b->index, &size);
	if (target_pos == -1)
		target_pos = ft_find_min_pos(stacks->a, size);
	return (target_pos);
}
