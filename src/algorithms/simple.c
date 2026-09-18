/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 17:04:32 by maridos-          #+#    #+#             */
/*   Updated: 2026/09/17 23:39:03 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a_top(t_stacks *stacks, t_data *data, int pos, int total)
{
	if (pos <= total - pos)
	{
		while (pos > 0)
		{
			ft_do_op(RA, stacks, data);
			pos--;
		}
	}
	else
	{
		while (pos < total)
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

    if (data->total_nbs <= 5)
        ft_sort_small(stacks, data);
    else
    {
        count = data->total_nbs;
        while (count > 0)
        {
            if (count == 1)
                pos = 0;
            else
                pos = ft_find_min(stacks->a);
            ft_rotate_a_top(stacks, data, pos, count);
            ft_do_op(PB, stacks, data);
            count--;
        }
        count = data->total_nbs;
        while (count > 0)
        {
            ft_do_op(PA, stacks, data);
            count--;
        }        
    }
}