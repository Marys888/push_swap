/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msievier <msievier@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 18:30:52 by msievier          #+#    #+#             */
/*   Updated: 2026/08/29 18:30:52 by msievier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*stack_new_node(int value)
{
	t_node	node;

	node = malloc(size_of(t_node));
	if(!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	stack_push_front(t_stack *s, t_node *node)
{
	if (!s || !node)
		return;
	node->next = s->top;
	node->prev = NULL;
	if (s->top)
		s->top->prev = node;
	s->top = node;
	s->size++;
}