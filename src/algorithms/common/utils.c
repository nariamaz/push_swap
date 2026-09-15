/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 16:02:43 by maridos-          #+#    #+#             */
/*   Updated: 2026/09/15 15:47:21 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_assign_index(t_stack *stack, int total_nbs)
{
    t_stack *current;
    t_stack *compare;
    int rank;
    int i;

    current = stack;
    i = 0;
    while (i < total_nbs)
    {
        compare = current->next;
        rank = 0;
        while (compare != current)
        {
            if (current-> content > compare->content)
                rank++;
            compare = compare->next;
        }
        current->index = rank;
        current = current->next;
        i++;
    }
}

int ft_calc_k(int total_nbs)
{
    int max_value;
    int k;
    
    max_value = total_nbs - 1;
    k = 0;
    while (max_value > 0)
    {
        max_value >>= 1;
        k++;        
    }
    return (k);
}

int ft_find_min(t_stack *stack)
{
    t_stack *current;
    int      min_position;
    int      min_value;
    int      i;

    current = stack;
    min_value = current->content;
    min_position = 0;
    i = 0;
    while (current->next != stack)
    {
        current = current->next;
        i++;
        if (current->content < min_value)
        {
            min_value = current->content;
            min_position = i;
        }
    }
    return (min_position);
}

void ft_do_op(t_operations op, t_stacks *stacks, t_data *data)
{
    if (op == SA)
        sa(&stacks->a);
    else if (op == SB)
        sb(&stacks->b);
    else if (op == SS)
        ss(&stacks->a, &stacks->b);
    else if (op == PA)
        pa(&stacks->a, &stacks->b);
    else if (op == PB)
        pb(&stacks->a, &stacks->b);
    else if (op == RA)
        ra(&stacks->a);
    else if (op == RB)
        rb(&stacks->b);
    else if (op == RR)
        rr(&stacks->a, &stacks->b);
    else if (op == RRA)
        rra(&stacks->a);
    else if (op == RRB)
        rrb(&stacks->b);
    else
        rrr(&stacks->a, &stacks->b);
    data->op_counter[op]++;
    ft_putstr_fd((char *)data->op_names[op], 1);
    ft_putchar_fd('\n', 1);
}
