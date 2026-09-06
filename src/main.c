/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 14:39:00 by maridos-          #+#    #+#             */
/*   Updated: 2026/09/04 13:19:59 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int init_stack(int argc, char **argv, t_data* data, t_stack **stack_a)
{
	if (!ft_validate_args(argc, argv, data))
		return (0);
	if (!ft_check_duplicate_f(data))
		return (0);
	if (!ft_fill_stack(argc, argv, stack_a))
		return (0);
	return (1);
}

static int select_strategy (t_data *data, t_stack *stack_a)
{
	ft_compute_disorder(stack_a, data);
	if (data->disorder == 0 && data->f_counter[BENCH])
	{
		ft_show_benchmark(*(data));
		return (0);
	}
	if (data->disorder == 0)
		return (0);
	ft_get_strategy(data);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_data data;

	stack_a = NULL;
	data = (t_data){0};
	if (!init_stack(argc, argv, &data, &stack_a))
		return (0);
	if (!select_strategy (&data, stack_a))
		return (0);
	if (data.f_counter[BENCH])
		ft_show_benchmark(data);
	return (0);
}
