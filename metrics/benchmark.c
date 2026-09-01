/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 02:00:52 by maridos-          #+#    #+#             */
/*   Updated: 2026/09/01 21:11:57 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

static void ft_print_sumop()
{
    ft_putstr_fd("[bench] total_ops: ", 2);
    ft_putnbr_fd(ft_total_ops(metrics), 2);
    ft_putchar_fd('\n', 2);
}
void ft_show_benchmark()
{
    t_metrics metrics;
    
    metrics = (t_metrics){0};
    ft_print_sumop();
}