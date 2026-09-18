/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 21:46:55 by maridos-          #+#    #+#             */
/*   Updated: 2026/09/17 23:39:57 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_find_min_pos(t_stack *stack)
{
	t_stack *current;
    int	min;
	int	pos;
	int	i;

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
	int	a;
	int	b;
	int	c;

	a = stacks->a->index;
	b = stacks->a->next->index;
	c = stacks->a->next->next->index;
	if (a < c && c < b)
	{
		ft_do_op(SA, stacks, data);
		ft_do_op(RA, stacks, data);
	}
	else if (b < a && a < c)
		ft_do_op(SA, stacks, data);
	else if (c < a && a < b)
		ft_do_op(RRA, stacks, data);
	else if (b < c && c < a)
		ft_do_op(RA, stacks, data);
	else if (c < b && b < a)
	{
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
	{
		ft_assign_index(stacks->a, data->total_nbs);
		ft_push_two_min(stacks, data);		
	}
	ft_sort_three(stacks, data);
	ft_do_op(PA, stacks, data);
	ft_do_op(PA, stacks, data);
}
