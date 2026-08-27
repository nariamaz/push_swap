/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hequeiro <hequeiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 14:20:23 by hequeiro          #+#    #+#             */
/*   Updated: 2026/08/27 17:04:51 by hequeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	print_list(t_stack *stack)
{
	t_stack	*head;

	head = stack;
	print_node(stack);
	if (stack != NULL)
	{
		stack = stack->next;
		while (stack != head && stack != NULL)
		{
			print_node(stack);
			stack = stack->next;
		}
	}
}

void	print_node(t_stack *node)
{
	if (node == NULL)
	{
		printf("Empty list\n");
		return ;
	}
	printf("Current Node's content: %d\n", node->content);
	if (node->next == NULL)
	{
		printf("\tNext's content: (null)\n");
		printf("\tPrevious's content: (null)\n");
	}
	else
	{
		printf("\tNext's content: %d\n", (node->next)->content);
		printf("\tPrevious's content: %d\n", (node->prev)->content);
	}
	printf("---------------------\n");
}
