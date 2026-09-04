/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msievier <msievier@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 15:48:54 by msievier          #+#    #+#             */
/*   Updated: 2026/09/03 15:48:54 by msievier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int 	find_min_position(t_stack *a)
{
	t_node	*current;
	int		min_index;
	int		best_position;
	int		position;

	current = a->top;
	min_index = current->index;
	best_position = 0;
	position = 0;
	while (current)
	{
		if (current->index < min_index)
		{
			min_index = current->index;
			best_position  = position;
		}
		current = current->next;
		position++;
	}
	return (best_position);
}

static void	move_min_to_top(t_stack *a, t_stack *b, t_bench *bench)
{
	int	pos;
	int	half;

	pos = find_min_position(a);
	half = a->size / 2;
	if (pos <= half)
	{
		while (pos-- > 0)
			do_op(RA, a, b, bench);
	}
	else
	{
		while (pos++ < a->size)
			do_op(RRA, a, b, bench);
	}
}

void	sort_simple(t_stack *a, t_stack *b, t_bench *bench)
{
	while (a->size > 0)
	{
		move_min_to_top(a, b, bench);
		do_op(PB, a, b, bench);
	}
	while (b->size > 0)
	{
		do_op(PA, a, b, bench);
	}
}