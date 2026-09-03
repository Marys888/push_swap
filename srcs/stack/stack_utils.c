/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msievier <msievier@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 18:48:11 by msievier          #+#    #+#             */
/*   Updated: 2026/08/29 18:48:11 by msievier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *s)
{
	if (!s)
		return (0);
	return (s->size);
}

int	stack_is_sorted(t_stack *s)
{
	t_node	*current;

	if (!s || !s->top)
		return (1);
	current = s->top;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	stack_get_min_index(t_stack *s)
{
	t_node	*current;
	int		min_index;
	int		position;
	int		best_position;

	current = s->top;
	min_index = current->index;
	best_position = 0;
	position = 0;
	while (current)
	{
		if (current->index < min_index)
		{
			min_index = current->index;
			best_position = position;

		}
		current = current->next;
		position++;
	}
	return (best_position);
}
