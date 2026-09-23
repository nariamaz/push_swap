/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 17:04:25 by maridos-          #+#    #+#             */
/*   Updated: 2026/09/22 15:49:13 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_chunks_to_b(t_stacks *stacks, int chunk_base, t_data *data)
{
	int	chunk_limit;
	int	pushed;
	int	stack_a;

	pushed = 0;
	chunk_limit = chunk_base;
	stack_a = data->total_nbs;
	while (stack_a > 3)
	{
		if (stacks->a->index < chunk_limit)
		{
			ft_do_op(PB, stacks, data);
			pushed++;
			stack_a--;
			if (pushed >= chunk_limit)
				chunk_limit += chunk_base;
		}
		else
			ft_do_op(RA, stacks, data);
	}
}

static void	final_alignment(t_stacks *stacks, t_data *data)
{
	int	pos_min;

	pos_min = ft_find_min_pos(stacks->a, data->total_nbs);
	ft_rotate_a_top(stacks, data, pos_min, data->total_nbs);
}

static void	push_all_to_a(t_stacks *stacks, t_data *data)
{
	int	size_a;
	int	pos_to_insert;

	size_a = 3;
	while (stacks->b)
	{
		pos_to_insert = get_target_for_b(stacks);
		ft_rotate_a_top(stacks, data, pos_to_insert, size_a);
		ft_do_op(PA, stacks, data);
		size_a++;
	}
}

void	ft_sort_medium(t_stacks *stacks, t_data *data)
{
	int	chunk_base;

	chunk_base = ft_sqrt(data->total_nbs);
	push_chunks_to_b(stacks, chunk_base, data);
	ft_sort_three(stacks, data);
	push_all_to_a(stacks, data);
	final_alignment(stacks, data);
}