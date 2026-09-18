/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 23:03:48 by maridos-          #+#    #+#             */
/*   Updated: 2026/09/08 17:26:38 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_compute_disorder(t_stack *stack, t_data *data)
{
	int	mistakes;
	int	total_pairs;

	mistakes = 0;
	total_pairs = 0;
	while (total_pairs < (data->total_nbs - 1))
	{
		total_pairs++;
		if ((stack -> content) > (stack -> next -> content))
			mistakes++;
		stack = stack -> next;
	}
	data->disorder = ((double) mistakes / total_pairs);
}

void	ft_get_strategy(t_data *data, t_stacks *stacks)
{
	if (data->f_counter[SIMPLE])
	{
		data->strategy = SIMPLE;
		data->strategy_selected = SIMPLE;
		ft_sort_simple(stacks, data);
	}
	else if (data->f_counter[MEDIUM])
	{
		data->strategy = MEDIUM;
		data->strategy_selected = MEDIUM;
		ft_sort_medium(stacks, data);
	}
	else if (data->f_counter[COMPLEX])
	{
		data->strategy = COMPLEX;
		data->strategy_selected = COMPLEX;
		ft_sort_complex(stacks, data);
	}
	else
		ft_adaptive_strategy(stacks, data);
}

void	ft_adaptive_strategy(t_stacks *stacks, t_data *data)
{
	if (data->disorder < 0.2)
	{
		data->strategy = ADAPTIVE;
		data->strategy_selected = SIMPLE;
		ft_sort_simple(stacks, data);
	}
	else if (data->disorder < 0.5)
	{
		data->strategy = ADAPTIVE;
		data->strategy_selected = MEDIUM;
		ft_sort_medium(stacks, data);
	}
	else
	{
		data->strategy = ADAPTIVE;
		data->strategy_selected = COMPLEX;
		ft_sort_complex(stacks, data);
	}
}
