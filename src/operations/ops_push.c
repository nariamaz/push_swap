/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hequeiro <hequeiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 18:21:58 by hequeiro          #+#    #+#             */
/*   Updated: 2026/08/27 18:21:58 by hequeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <assert.h>

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
	// 0 nodes in DST
	if (*dst == NULL)
		set_node_directions(&node, NULL, NULL);
	// 1 node in DST
	else if ((*dst)->next == NULL)
	{
		set_node_directions(dst, node, node);
		set_node_directions(&node, *dst, *dst);
	}
	// 2+ nodes in DST
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
	// If originally 1 node in SRC
	// Naturally will point to NULL at the end
	if (prev && next)
	{
		// Originally 2 nodes in SRC
		if (prev == next)
			set_node_directions(&next, NULL, NULL);
		// Originally 2+ nodes in SRC
		else
		{
			prev->next = next;
			next->prev = prev;
		}
	}
	*src = next;
}
