/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 17:04:25 by maridos-          #+#    #+#             */
/*   Updated: 2026/09/16 16:03:08 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//dummy function
void ft_sort_medium(t_stacks *stacks, t_data *data)
{
    if (stacks->a == NULL)
        return ;
    if (data->total_nbs == 0)
    return ;
}

int ft_sqrt(int nb)
{
    int i;

    i = 0;
    if (nb <= 0)
        return (0);
    while (i*i <= nb)
        i++;
    return (i - 1);
}