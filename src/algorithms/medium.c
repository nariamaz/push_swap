/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hequeiro <hequeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 17:04:25 by maridos-          #+#    #+#             */
/*   Updated: 2026/09/18 10:36:16 by hequeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_separate_chunks(t_stacks *stacks, t_data *data, int chunk)
{
	int	b_counter;
	int	seen;
	int	i;

	i = 0;
	b_counter = 0;
	while (b_counter < data->total_nbs)
	{
		seen = 0;
		while (seen < data->total_nbs - b_counter)
		{
			if (stacks->a->index >= (chunk * i)
				&& stacks->a->index <= ((chunk - 1) + (chunk * i)))
			{
				ft_do_op(PB, stacks, data);
				b_counter++;
			}
			else
			{
				ft_do_op(RA, stacks, data);
				seen++;
			}
		}
		i++;
	}
}

static void	ft_rotate_b_top(t_stacks *stacks, t_data *data, int pos, int count)
{
	if (pos <= count - pos)
	{
		while (pos > 0)
		{
			ft_do_op(RB, stacks, data);
			pos--;
		}
	}
	else
	{
		while (pos < count)
		{
			ft_do_op(RRB, stacks, data);
			pos++;
		}
	}
}

static void	ft_merge_chunks(t_stacks *stacks, t_data *data, int chunk_size)
{
	int	b_counter;
	int	max;

	b_counter = data->total_nbs;
	while (b_counter > 0)
	{
		if (b_counter == 1)
			max = 0;
		else
			max = ft_find_max_in_chunk(stacks->b, chunk_size);
		ft_rotate_b_top(stacks, data, max, b_counter);
		ft_do_op(PA, stacks, data);
		b_counter--;
	}
}

void	ft_sort_medium(t_stacks *stacks, t_data *data)
{
	int	chunk_size;

	if (data->total_nbs <= 5)
		ft_sort_small(stacks, data);
	else
	{
		chunk_size = ft_sqrt(data->total_nbs);
		ft_separate_chunks(stacks, data, chunk_size);
		ft_merge_chunks(stacks, data, chunk_size);
	}
}

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
		return (0);
	while (i * i <= nb)
		i++;
	return (i - 1);
}
