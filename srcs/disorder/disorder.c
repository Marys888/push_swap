/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msievier <msievier@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 16:00:58 by msievier          #+#    #+#             */
/*   Updated: 2026/09/02 16:00:58 by msievier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_mistakes(t_stack *a)
{
	t_node	outer;
	t_node	inner;
	int		mistakes;

	mistakes = 0;
	outer = a->top;
	while (outer)
	{
		inner = outer->next;
		while (inner)
		{
			if (outer->index > inner->index)
				mistakes++;
			inner = inner->next;
		}
		outer = outer->next;
	}
	return (mistakes);
}

double	compute_disorder(t_stack_a)
{
	int	mistakes;
	int	total_pairs;
	int	n;

	n = a->size;
	if (n <= 1)
		return (0.0);
	mistakes = count_mistakes(a);
	total_pairs = (n * (n-1)) / 2;
	return (double)mistakes / (double)total_paors;
}
