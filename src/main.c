/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 14:39:00 by maridos-          #+#    #+#             */
/*   Updated: 2026/09/23 10:26:22 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	init_stack(int argc, char **argv, t_data *data, t_stack **stack_a)
{
	if (!ft_validate_args(argc, argv, data))
		return (0);
	if (data->total_nbs == 1)
		return (0);
	if (!ft_check_duplicate_f(data))
		return (0);
	if (!ft_fill_stack(argc, argv, stack_a))
		return (0);
	return (1);
}

static int	select_strategy(t_data *data, t_stacks *stacks)
{
	ft_compute_disorder(stacks->a, data);
	if (data->disorder == 0)
	{
		clean_list(&stacks->a);
		return (0);
	}
	ft_get_strategy(data, stacks);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_stacks	stacks;
	t_data		data;

	stack_a = NULL;
	stack_b = NULL;
	data = (t_data){0};
	ft_init_op_names(&data);
	if (!init_stack(argc, argv, &data, &stack_a))
		return (0);
	stacks.a = stack_a;
	stacks.b = stack_b;
	ft_assign_index(stacks.a, data.total_nbs);
	if (!select_strategy (&data, &stacks))
		return (0);
	clean_list(&stacks.a);
	if (data.f_counter[BENCH])
		ft_show_benchmark(data);
	return (0);
}
