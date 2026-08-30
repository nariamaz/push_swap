/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hequeiro <hequeiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 11:58:35 by hequeiro          #+#    #+#             */
/*   Updated: 2026/08/30 11:58:35 by hequeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rx(t_stack **stack)
{
	if (*stack == NULL)
		return ;
	if ((*stack)->next == NULL)
		return ;
	*stack = (*stack)->next;
}

void	ra(t_stack **stack)
{
	rx(stack);
}

void	rb(t_stack **stack)
{
	rx(stack);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rx(stack_a);
	rx(stack_b);
}
