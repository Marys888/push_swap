/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cathrinevarlamova <cathrinevarlamova@student.42.fr>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-09-06 17:10:04 by cathrinevarlamova #+#    #+#             */
/*   Updated: 2026-09-06 17:10:04 by cathrinevarlamova ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_stack(t_node **stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	first = *stack;
	second = first->next;
	third = second->next;
	second->next = first;
	first->next = third;
	*stack = second;
}

void	sa(t_node **stack, t_bench *bench)
{
	if (!*stack || !(*stack)->next)
		return ;
	swap_stack(stack);
	write(1, "sa\n", 3);
	bench->sa++;
	bench->total++;
}

void	sb(t_node **stack, t_bench *bench)
{
	if (!*stack || !(*stack)->next)
		return ;
	swap_stack(stack);
	write(1, "sb\n", 3);
	bench->sb++;
	bench->total++;
}

void	ss(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	if (*stack_a && (*stack_a)->next)
		swap_stack(stack_a);
	if (*stack_b && (*stack_b)->next)
		swap_stack(stack_b);
	write(1, "ss\n", 3);
	bench->ss++;
	bench->total++;
}
