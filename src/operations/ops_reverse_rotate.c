/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hequeiro <hequeiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 12:29:03 by hequeiro          #+#    #+#             */
/*   Updated: 2026/08/30 12:29:03 by hequeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rrx(t_stack **stack)
{
	if (*stack == NULL)
		return ;
	if ((*stack)->next == NULL)
		return ;
	*stack = (*stack)->prev;
}

void	rra(t_stack **stack)
{
	rrx(stack);
}

void	rrb(t_stack **stack)
{
	rrx(stack);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rrx(stack_a);
	rrx(stack_b);
}
