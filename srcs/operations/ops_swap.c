/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msievier <msievier@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 17:58:38 by msievier          #+#    #+#             */
/*   Updated: 2026/09/02 17:58:38 by msievier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_sa(t_stack *a)
{
	t_node	*first;
	t_node	*second;

	if (!a->top || !a->top->next)
		return;
	first = a->top;
	second = a->top->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	a->top = second;
}

void	op_sb(t_stack *b)
{
	t_node	*first;
	t_node	*second;

	if (!b->top || !b->top->next)
		return;
	first = b->top;
	second = b->top->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	b->top = second;
}

void	op_ss(t_stack *a, t_stack *b)
{
	op_sa(a);
	op_sb(b);
}
