/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 17:13:40 by maridos-          #+#    #+#             */
/*   Updated: 2026/09/01 21:57:47 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

void ft_print_counts(t_metrics *metrics)
{
    const char *op_names[] = {
    "sa", "sb", "ss", "pa", "pb", "ra", 
    "rb", "rr","rra", "rrb", "rrr"
    };
    int i;

    i = 0;
    ft_putstr_fd("[bench] ", 2);
    while (i < OP_COUNT)
    {
        ft_putstr_fd((char *)op_names[i], 2);
        ft_putstr_fd(": ", 2);
        ft_putnbr_fd(metrics->op_counter[i], 2);
        if (i == PB)
        {
            ft_putchar_fd('\n', 2);
            ft_putstr_fd("[bench] ", 2);
        }
        else if (i != PB && i != RRR)
            ft_putchar_fd(' ', 2);
        i++;
    }
    ft_putchar_fd('\n', 2);
}

int ft_total_ops(t_metrics metrics)
{
    int i;
    int sum;
    
    i = 0;
    sum = 0;
    while (i < OP_COUNT)
    {
        sum = sum + metrics.op_counter[i];
        i++;
    }
    return (sum);
}
