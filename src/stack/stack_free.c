/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hequeiro <hequeiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 14:16:56 by hequeiro          #+#    #+#             */
/*   Updated: 2026/08/27 17:04:49 by hequeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean_list(t_stack **stack)
{
	t_stack	*next_node;

	if (*stack == NULL)
		return ;
	if ((*stack)->next == NULL)
	{
		free(*stack);
		*stack = NULL;
		return ;
	}
	(*stack)->prev->next = NULL;
	next_node = (*stack)->next;
	free(*stack);
	*stack = next_node;
	while (*stack != NULL)
	{
		next_node = (*stack)->next;
		free(*stack);
		*stack = next_node;
	}
}
