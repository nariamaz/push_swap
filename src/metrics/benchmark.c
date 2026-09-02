/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 02:00:52 by maridos-          #+#    #+#             */
/*   Updated: 2026/09/02 00:02:33 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

static void ft_print_disorder(t_metrics metrics)
{
    int disorder_x10k;
    
    disorder_x10k = metrics.disorder * 10000; 
    ft_putstr_fd("[bench] disorder: ", 2); 
    ft_putnbr_fd((disorder_x10k / 100), 2);
    ft_putchar_fd('.', 2); 
    ft_putnbr_fd((disorder_x10k % 100), 2);  
    ft_putstr_fd("%\n", 2); 
}
static void ft_print_strategy(t_metrics metrics)
{
    ft_putstr_fd("[bench] strategy: ", 2);
    // INSERIR ALGORITMO EMPREGADO
    ft_putchar_fd(' / ', 2);
    // INSERIR COMPLEXIDADE 
    ft_putchar_fd('\n', 2);
}
static void ft_print_sumop(t_metrics metrics)
{
    ft_putstr_fd("[bench] total_ops: ", 2);
    ft_putnbr_fd(ft_total_ops(metrics), 2);
    ft_putchar_fd('\n', 2);
}
void ft_show_benchmark(t_metrics metrics)
{
    ft_print_disorder(metrics); 
    ft_print_strategy(metrics); 
    ft_print_sumop(metrics); 
}
