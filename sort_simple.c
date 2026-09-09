/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cathrinevarlamova <cathrinevarlamova@student.42.fr>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-09-06 18:54:42 by cathrinevarlamova #+#    #+#             */
/*   Updated: 2026-09-06 18:54:42 by cathrinevarlamova ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_node *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

int	find_min(t_node *stack)
{
	int	min;

	min = stack->content;
	while (stack)
	{
		if (stack->content < min)
			min = stack->content;
		stack = stack->next;
	}
	return (min);
}

int	find_position(t_node *stack, int value)
{
	int	position;

	position = 0;
	while (stack)
	{
		if (stack->content == value)
			return (position);
		position++;
		stack = stack->next;
	}
	return (-1);
}

void	sort_simple(t_node **a, t_node **b, t_bench *bench)
{
	int	min;
	int	pos;
	int	size;

	while (stack_size(*a) > 1)
	{
		min = find_min(*a);
		size = stack_size(*a);
		while ((*a)->content != min)
		{
			pos = find_position(*a, min);
			if (pos <= size / 2)
				ra(a, bench);
			else
				rra(a, bench);
		}
		pb(a, b, bench);
	}
	while (*b)
		pa(a, b, bench);
}
