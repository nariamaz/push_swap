/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 23:03:48 by maridos-          #+#    #+#             */
/*   Updated: 2026/09/01 17:14:33 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double ft_compute_disorder(t_stack *stack, int total_numbers)
{
    int mistakes;
    int total_pairs;
    
    mistakes = 0;
    total_pairs = 0;
    while (total_pairs < (total_numbers - 1))
    {
        total_pairs++;
        if ((stack -> content) > (stack -> next -> content))
            mistakes++;
        stack = stack -> next;
    }
    return ((double) mistakes / total_pairs);
}

