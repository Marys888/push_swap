/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msievier <msievier@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 21:17:14 by msievier          #+#    #+#             */
/*   Updated: 2026/09/09 21:17:16 by msievier         ###   ########.fr       */
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
