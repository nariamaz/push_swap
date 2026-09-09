/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 17:13:40 by maridos-          #+#    #+#             */
/*   Updated: 2026/09/08 15:58:49 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_init_op_names(t_data *data)
{
    data->op_names[SA] = "sa";
    data->op_names[SB] = "sb";
    data->op_names[SS] = "ss";
    data->op_names[PA] = "pa";
    data->op_names[PB] = "pb";
    data->op_names[RA] = "ra";
    data->op_names[RB] = "rb";
    data->op_names[RR] = "rr";
    data->op_names[RRA] = "rra";
    data->op_names[RRB] = "rrb";
    data->op_names[RRR] = "rrr";
}

void ft_print_counts(t_data data)
{
    int i;

    i = 0;
    ft_putstr_fd("[bench] ", 2);
    while (i < OP_COUNT)
    {
        ft_putstr_fd((char *)data.op_names[i], 2);
        ft_putstr_fd(": ", 2);
        ft_putnbr_fd(data.op_counter[i], 2);
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

int ft_total_ops(t_data data)
{
    int i;
    int sum;

    i = 0;
    sum = 0;
    while (i < OP_COUNT)
    {
        sum = sum + data.op_counter[i];
        i++;
    }
    return (sum);
}
