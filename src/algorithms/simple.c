/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 17:04:32 by maridos-          #+#    #+#             */
/*   Updated: 2026/09/09 06:29:05 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ft_rotate_to_top(t_stacks *stacks, t_data *data, int pos, int count)
{
    if (pos <= count - pos)
    {
        while (pos > 0)
        {
            ft_do_op(RA, stacks, data);
            pos--;
        }
    }
    else
    {
        while (pos < count)
        {
            ft_do_op(RRA, stacks, data);
            pos++;
        }
    }
}

void ft_sort_simple(t_stacks *stacks, t_data *data)
{
    int count;
    int pos;

    count = data->total_nbs;
    while (count > 0)
    {
        pos = ft_find_min(stacks->a);
        ft_rotate_to_top(stacks, data, pos, count);
        ft_do_op(PB, stacks, data);
        count--;
    }
    count = data->total_nbs;
    while (count-- > 0)
        ft_do_op(PA, stacks, data);
}