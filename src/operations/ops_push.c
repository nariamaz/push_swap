/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 18:21:58 by hequeiro          #+#    #+#             */
/*   Updated: 2026/09/23 10:17:21 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <assert.h>
#include <stdio.h>

static void	set_node_directions(t_stack **node, t_stack *prev, t_stack *next);
static void	stitch_src(t_stack **src, t_stack *prev, t_stack *next);

static void	px(t_stack **src, t_stack **dst)
{
	t_stack	*tmp_prev;
	t_stack	*tmp_next;
	t_stack	*node;

	node = *src;
	tmp_prev = (*src)->prev;
	tmp_next = (*src)->next;
	if (*dst == NULL)
		set_node_directions(&node, NULL, NULL);
	else if ((*dst)->next == NULL)
	{
		set_node_directions(dst, node, node);
		set_node_directions(&node, *dst, *dst);
	}
	else
	{
		set_node_directions(&node, (*dst)->prev, *dst);
		node->prev->next = node;
		node->next->prev = node;
	}
	*dst = node;
	stitch_src(src, tmp_prev, tmp_next);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_b == NULL)
		return ;
	px(stack_b, stack_a);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a == NULL)
		return ;
	px(stack_a, stack_b);
}

static void	set_node_directions(t_stack **node, t_stack *prev, t_stack *next)
{
	if (*node != NULL)
	{
		(*node)->prev = prev;
		(*node)->next = next;
	}
}

static void	stitch_src(t_stack **src, t_stack *prev, t_stack *next)
{
	if (prev && next)
	{
		if (prev == next)
			set_node_directions(&next, NULL, NULL);
		else
		{
			prev->next = next;
			next->prev = prev;
		}
	}
	*src = next;
}
