/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 22:12:26 by maridos-          #+#    #+#             */
/*   Updated: 2026/09/15 16:55:04 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_sort_complex(t_stacks *stacks, t_data *data)
{
    int counter;
    int bits_needed;
    int bits_moved;
    
    ft_assign_index(stacks->a, data->total_nbs);
    bits_needed = ft_calc_k(data->total_nbs);
    bits_moved = 0;
    counter = 0;
    while (bits_needed > 0)
    {
        while (counter < data->total_nbs)
        {
            if (((stacks->a->index >> bits_moved) & 1) == 1)
                ft_do_op(RA, stacks, data);
            else
                ft_do_op(PB, stacks, data);
            counter++;
        }
        while (counter > 0)
        {   
            ft_do_op(PA, stacks, data);
            counter --;
        }
        bits_moved++;
        bits_needed--;
    }
    print_list(stacks->a);
}
