/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msievier <msievier@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 18:48:18 by msievier          #+#    #+#             */
/*   Updated: 2026/08/29 18:48:18 by msievier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_clear(t_stack *s)
{
	t_node	*current;
	t_node	*next;

	if (!s)
		return;
	current = s->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	s->top = NULL;
	s->size = 0;
}