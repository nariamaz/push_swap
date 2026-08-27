/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hequeiro <hequeiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 15:13:28 by hequeiro          #+#    #+#             */
/*   Updated: 2026/08/27 17:04:40 by hequeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*create_node(int new_content, t_stack *prev, t_stack *next);

void	add_to_list(t_stack **head, int new_content)
{
	t_stack	*new_node;
	t_stack	*tail;

	if (*head == NULL)
		*head = create_node(new_content, NULL, NULL);
	else if ((*head)->next == NULL)
	{
		new_node = create_node(new_content, *head, *head);
		(*head)->next = new_node;
		(*head)->prev = new_node;
	}
	else
	{
		tail = (*head)->prev;
		new_node = create_node(new_content, tail, *head);
		tail->next = new_node;
		(*head)->prev = new_node;
	}
}

static t_stack	*create_node(int new_content, t_stack *prev, t_stack *next)
{
	t_stack	*new_node;

	new_node = ft_calloc(1, sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->content = new_content;
	new_node->prev = prev;
	new_node->next = next;
	return (new_node);
}
