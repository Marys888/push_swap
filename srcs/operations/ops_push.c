/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msievier <msievier@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 18:26:17 by msievier          #+#    #+#             */
/*   Updated: 2026/09/02 18:26:17 by msievier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_pa(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (!b->top)
		return;
	node = b->top;
	b->top = b->top->next;
	if (b->top)
		b->top->prev = NULL;
	b->size--;
	node->next = a->top;
	node->prev = NULL;
	if (a->top)
		a->top->prev = node;
	a->top = node;
	a->size++;
}

void	op_pb(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (!a->top)
		return;
	node = a->top;
	a->top = a->top->next;
	if (a->top)
		a->top->prev = NULL;
	a->size--;
	node->next = b->top;
	node->prev = NULL;
	if (b->top)
		b->top->prev = node;
	b->top = node;
	b->size++;
}
