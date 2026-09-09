/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cathrinevarlamova <cathrinevarlamova@student.42.fr>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-09-06 18:49:40 by cathrinevarlamova #+#    #+#             */
/*   Updated: 2026-09-06 18:49:40 by cathrinevarlamova ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_stack(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	first = *stack;
	*stack = first->next;
	last = *stack;
	while (last->next)
		last = last->next;
	first->next = NULL;
	last->next = first;
}

void	ra(t_node **stack, t_bench *bench)
{
	if (!*stack || !(*stack)->next)
		return ;
	rotate_stack(stack);
	write(1, "ra\n", 3);
	bench->ra++;
	bench->total++;
}

void	rb(t_node **stack, t_bench *bench)
{
	if (!*stack || !(*stack)->next)
		return ;
	rotate_stack(stack);
	write(1, "rb\n", 3);
	bench->rb++;
	bench->total++;
}

void	rr(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	if (*stack_a && (*stack_a)->next)
		rotate_stack(stack_a);
	if (*stack_b && (*stack_b)->next)
		rotate_stack(stack_b);
	write(1, "rr\n", 3);
	bench->rr++;
	bench->total++;
}
