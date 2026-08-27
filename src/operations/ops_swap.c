/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hequeiro <hequeiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 17:22:38 by hequeiro          #+#    #+#             */
/*   Updated: 2026/08/27 18:05:31 by hequeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sx(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack == NULL)
		return ;
	if ((*stack)->next == NULL)
		return ;
	first = *stack;
	second = (*stack)->next;
	if (first->next->next == first)
	{
		first->prev = second;
		first->next = second;
		second->prev = first;
		second->next = first;
	}
	else
	{
		first->next = second->next;
		second->prev = first->prev;
		first->prev = second;
		second->next = first;
	}
	*stack = second;
}

void	sa(t_stack	**stack)
{
	sx(stack);
}

void	sb(t_stack	**stack)
{
	sx(stack);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sx(stack_a);
	sx(stack_b);
}
