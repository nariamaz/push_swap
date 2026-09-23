/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 15:49:45 by maridos-          #+#    #+#             */
/*   Updated: 2026/09/22 15:49:58 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	t_stack	*current_a;
	int		min_bigger;
	int		target_pos;
	int		i;

	if (!stacks->a)
		return (0);
	current_a = stacks->a;
	min_bigger = 2147483647;
	target_pos = -1;
	i = 0;
	while (current_a)
	{
		if (current_a->index > stacks->b->index
			&& current_a->index < min_bigger)
		{
			min_bigger = current_a->index;
			target_pos = i;
		}
		current_a = current_a->next;
		i++;
		if (current_a == stacks->a)
			break ;
	}
	if (target_pos == -1)
		target_pos = ft_find_min_pos(stacks->a, i);
	return (target_pos);
}