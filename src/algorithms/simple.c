/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 17:04:32 by maridos-          #+#    #+#             */
/*   Updated: 2026/09/17 03:33:23 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_find_min_pos(t_stack *stack)
{
	int	min;
	int	pos;
	int	i;

	min = stack->index;
	pos = 0;
	i = 0;
	while (stack)
	{
		if (stack->index < min)
		{
			min = stack->index;
			pos = i;
		}
		i++;
		stack = stack->next;
	}
	return (pos);
}

static void	ft_rotate_a_top(t_stacks *stacks, t_data *data, int pos, int total)
{
	if (pos <= total - pos)
	{
		while (pos > 0)
		{
			ft_do_op(RA, stacks, data);
			pos--;
		}
	}
	else
	{
		while (pos < total)
		{
			ft_do_op(RRA, stacks, data);
			pos++;
		}
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

static void	ft_sort_three(t_stacks *stacks, t_data *data)
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

static void	ft_sort_five(t_stacks *stacks, t_data *data)
{
	ft_assign_index(stacks->a, data->total_nbs);
	ft_push_two_min(stacks, data);
	ft_sort_three(stacks, data);
	ft_do_op(PA, stacks, data);
	ft_do_op(PA, stacks, data);
}

void ft_sort_simple(t_stacks *stacks, t_data *data)
{
    int count;
    int pos;

    if (data->total_nbs <= 5)
        ft_sort_five(stacks, data);
    else
    {
        count = data->total_nbs;
        while (count > 0)
        {
            if (count == 1)
                pos = 0;
            else
                pos = ft_find_min(stacks->a);
            ft_rotate_a_top(stacks, data, pos, count);
            ft_do_op(PB, stacks, data);
            count--;
        }
        count = data->total_nbs;
        while (count > 0)
        {
            ft_do_op(PA, stacks, data);
            count--;
        }        
    }
}