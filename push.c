/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cathrinevarlamova <cathrinevarlamova@student.42.fr>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-09-06 18:49:43 by cathrinevarlamova #+#    #+#             */
/*   Updated: 2026-09-06 18:49:43 by cathrinevarlamova ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	t_node	*node;

	if (!*stack_b)
		return ;
	node = *stack_b;
	*stack_b = node->next;
	node->next = *stack_a;
	*stack_a = node;
	write(1, "pa\n", 3);
	if (bench)
	{
		bench->pa++;
		bench->total++;
	}
}

void	pb(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	t_node	*node;

	if (!*stack_a)
		return ;
	node = *stack_a;
	*stack_a = node->next;
	node->next = *stack_b;
	*stack_b = node;
	write(1, "pb\n", 3);
	if (bench)
	{
		bench->pb++;
		bench->total++;
	}
}
