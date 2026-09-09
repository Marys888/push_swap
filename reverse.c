/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msievier <msievier@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 21:17:22 by msievier          #+#    #+#             */
/*   Updated: 2026/09/09 21:17:24 by msievier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_stack(t_node **stack)
{
	t_node	*prev;
	t_node	*last;

	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_node **stack, t_bench *bench)
{
	if (!*stack || !(*stack)->next)
		return ;
	reverse_stack(stack);
	write(1, "rra\n", 4);
	bench->rra++;
	bench->total++;
}

void	rrb(t_node **stack, t_bench *bench)
{
	if (!*stack || !(*stack)->next)
		return ;
	reverse_stack(stack);
	write(1, "rrb\n", 4);
	bench->rrb++;
	bench->total++;
}

void	rrr(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	if (*stack_a && (*stack_a)->next)
		reverse_stack(stack_a);
	if (*stack_b && (*stack_b)->next)
		reverse_stack(stack_b);
	write(1, "rrr\n", 4);
	bench->rrr++;
	bench->total++;
}
