/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hequeiro <hequeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 21:46:55 by maridos-          #+#    #+#             */
/*   Updated: 2026/09/18 12:23:23 by hequeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_find_min_pos(t_stack *stack)
{
	t_stack	*current;
	int		min;
	int		pos;
	int		i;

	current = stack;
	min = current->index;
	pos = 0;
	i = 0;
	while (current->next != stack)
	{
		current = current->next;
		i++;
		if (current->index < min)
		{
			min = stack->index;
			pos = i;
		}
	}
	return (pos);
}

void	ft_sort_three(t_stacks *stacks, t_data *data)
{
	if (stacks->a->index > stacks->a->next->index)
		ft_do_op(SA, stacks, data);
	
	if (stacks->a->index > stacks->a->prev->index)
		ft_do_op(RRA, stacks, data);
	else if (stacks->a->next->index > stacks->a->next->next->index)
	{
		ft_do_op(RA, stacks, data);
		ft_do_op(SA, stacks, data);
		ft_do_op(RRA, stacks, data);
	}
}

static void	ft_push_two_min(t_stacks *stacks, t_data *data)
{
	int	pos;

	pos = ft_find_min_pos(stacks->a);
	ft_rotate_a_top(stacks, data, pos, data->total_nbs);
	ft_do_op(PB, stacks, data);
	pos = ft_find_min_pos(stacks->a);
	ft_rotate_a_top(stacks, data, pos, data->total_nbs - 1);
	ft_do_op(PB, stacks, data);
}

void	ft_sort_small(t_stacks *stacks, t_data *data)
{
	if (data->total_nbs > 3)
		ft_push_two_min(stacks, data);
	ft_sort_three(stacks, data);
	if (data->total_nbs > 3)
	{
		ft_do_op(PA, stacks, data);
		ft_do_op(PA, stacks, data);
	}	
}
