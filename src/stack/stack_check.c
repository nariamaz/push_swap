/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hequeiro <hequeiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 14:19:54 by hequeiro          #+#    #+#             */
/*   Updated: 2026/08/27 17:04:43 by hequeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate_n(t_stack *stack, int num)
{
	t_stack	*head;

	if (stack == NULL)
		return (0);
	if (stack->next == NULL)
		return (stack->content == num);
	head = stack;
	if (stack->content == num)
		return (1);
	stack = stack->next;
	while (stack != head)
	{
		if (stack->content == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	check_list_integrity(t_stack *head)
{
	t_stack	*current;

	if (head == NULL)
		return (1);
	if (head->next == NULL && head->prev == NULL)
		return (1);
	current = head;
	while (1)
	{
		if (current->next->prev != current)
			return (0);
		if (current->prev->next != current)
			return (0);
		current = current->next;
		if (current == head)
			break ;
	}
	return (1);
}
