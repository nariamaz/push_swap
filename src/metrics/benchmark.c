/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 02:00:52 by maridos-          #+#    #+#             */
/*   Updated: 2026/09/08 17:03:01 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ft_print_disorder(t_data data)
{
    int disorder_x10k;

    disorder_x10k = data.disorder * 10000;
    ft_putstr_fd("[bench] disorder: ", 2);
    ft_putnbr_fd((disorder_x10k / 100), 2);
    ft_putchar_fd('.', 2);
    ft_putnbr_fd((disorder_x10k % 100), 2);
    ft_putstr_fd("%\n", 2);
}

static void	ft_print_strategy(t_data data)
{
    ft_putstr_fd("[bench] strategy: ", 2);
	if (data.strategy == SIMPLE)
		ft_putstr_fd("Simple /", 2);
	else if (data.strategy == MEDIUM)
		ft_putstr_fd("Medium /", 2);
	else if (data.strategy == COMPLEX)
		ft_putstr_fd("Complex /", 2);
	else if (data.strategy == ADAPTIVE)
		ft_putstr_fd("Adaptive /", 2);
}

static void	ft_print_complexity(t_data data)
{
	if (data.strategy_selected == SIMPLE)
		ft_putstr_fd(" O(n^2)\n", 2);
	else if (data.strategy_selected == MEDIUM)
		ft_putstr_fd(" O(n√n)\n", 2);
	else if (data.strategy_selected == COMPLEX)
		ft_putstr_fd(" O(n log n)\n", 2);
}

static void ft_print_sumop(t_data data)
{
    ft_putstr_fd("[bench] total_ops: ", 2);
    ft_putnbr_fd(ft_total_ops(data), 2);
    ft_putchar_fd('\n', 2);
}
void ft_show_benchmark(t_data data)
{
    ft_print_disorder(data);
    ft_print_strategy(data);
    ft_print_complexity(data);
    ft_print_sumop(data);
    ft_print_counts(data);
}
