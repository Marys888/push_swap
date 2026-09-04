/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msievier <msievier@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 18:26:23 by msievier          #+#    #+#             */
/*   Updated: 2026/09/02 18:26:23 by msievier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_stack(t_stack *s)
{
	t_node	*old_top;
	t_node	*last;

	if (!s->top || !s->top->next)
		return;
	old_top = s->top;
	s->top = s->top->next;
	s->top->prev = NULL;
	last = s->top;
	while (last->next)
		last = last->next;
	last->next = old_top;
	old_top->prev = last;
	old_top->next = NULL;
}

void	op_ra(t_stack *a)
{
	rotate_stack(a);
}

void	op_rb(t_stack *b)
{
	rotate_stack(b);
}

void	op_rr(t_stack *a, t_stack *b)
{
	op_ra(a);
	op_rb(b);
}