/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cathrinevarlamova <cathrinevarlamova@student.42.fr>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-09-06 18:55:06 by cathrinevarlamova #+#    #+#             */
/*   Updated: 2026-09-06 18:55:06 by cathrinevarlamova ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_chunk_pos(t_node *stack, int limit)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index <= limit)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}

static void	rotate_to_position(t_node **stack, int pos, t_bench *bench)
{
	int	size;

	size = stack_size(*stack);
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			ra(stack, bench);
			pos--;
		}
	}
	else
	{
		pos = size - pos;
		while (pos > 0)
		{
			rra(stack, bench);
			pos--;
		}
	}
}

static int	find_max_index(t_node *stack)
{
	int	max;
	int	value;

	max = stack->index;
	value = stack->content;
	while (stack)
	{
		if (stack->index > max)
		{
			max = stack->index;
			value = stack->content;
		}
		stack = stack->next;
	}
	return (value);
}

static void	push_back_sorted(t_node **a, t_node **b, t_bench *bench)
{
	int	max;
	int	pos;

	while (*b)
	{
		max = find_max_index(*b);
		pos = find_position(*b, max);
		if (pos <= stack_size(*b) / 2)
			while ((*b)->content != max)
				rb(b, bench);
		else
			while ((*b)->content != max)
				rrb(b, bench);
		pa(a, b, bench);
	}
}

void	sort_medium(t_node **a, t_node **b, t_bench *bench)
{
	int	chunk;
	int	limit;
	int	pos;

	chunk = stack_size(*a);
	chunk = 1;
	while (chunk * chunk < stack_size(*a))
		chunk++;
	limit = chunk - 1;
	while (*a)
	{
		pos = find_chunk_pos(*a, limit);
		if (pos == -1)
		{
			limit += chunk;
			continue ;
		}
		rotate_to_position(a, pos, bench);
		pb(a, b, bench);
		if ((*b)->index < limit - (chunk / 2))
			rb(b, bench);
		if (stack_size(*b) >= limit + 1)
			limit += chunk;
	}
	push_back_sorted(a, b, bench);
}
