/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 14:39:00 by maridos-          #+#    #+#             */
/*   Updated: 2026/09/02 00:00:02 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_state	flag;
	t_stack *stack_a; 
	t_metrics metrics; 
		
	flag    = (t_state){0};
	metrics = (t_metrics){0}; 
	stack_a = NULL;
	if (!ft_parse_arguments(argc, argv, &flag))
		return (0);
	if (!ft_check_duplicity(&flag))
		return (0);
	if (!ft_fill_stack(argc, argv, &stack_a))
		return (0);
	ft_get_strategy(flag, &metrics); 
	// Lógica intermediária
	ft_compute_disorder(stack_a, flag.total_nbs, &metrics); 
	if (flag.counter[BENCH])
		ft_show_benchmark(metrics); 
	return (0);
}
