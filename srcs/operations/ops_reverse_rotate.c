/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msievier <msievier@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 18:26:27 by msievier          #+#    #+#             */
/*   Updated: 2026/09/02 18:26:27 by msievier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate_stack(t_stack *s)
{
	t_node	*last;

	if (!s->top || !s->top->next)
		return;
	last = s->top;
	while(last->next)
		last = last->next;
	last->prev->next = NULL;
	s->top->prev = last;
	s->top = last;
}

void	op_rra(t_stack *a)
{
	reverse_rotate_stack(a);
}

void	op_rrb(t_stack *b)
{
	reverse_rotate_stack(b);
}

void	op_rrr(t_stack *a, t_stack *b)
{
	op_rra(a);
	op_rrb(b);
}
