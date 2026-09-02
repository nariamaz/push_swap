/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 23:03:48 by maridos-          #+#    #+#             */
/*   Updated: 2026/09/01 23:52:31 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_compute_disorder(t_stack *stack, int total_nbs, t_metrics *metrics)
{
    int mistakes;
    int total_pairs;
       
    mistakes = 0;
    total_pairs = 0;
    while (total_pairs < (total_nbs - 1))
    {
        total_pairs++;
        if ((stack -> content) > (stack -> next -> content))
            mistakes++;
        stack = stack -> next;
    }
    metrics->disorder = ((double) mistakes / total_pairs);
}

