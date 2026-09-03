/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msievier <msievier@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 15:34:56 by msievier          #+#    #+#             */
/*   Updated: 2026/09/02 15:34:56 by msievier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sorted_copy(t_stack *a)
{
	int		*values;
	t_node	*current;
	int		i;
	int		j;
	int		temp;

	values = malloc(sizeof(int) * a->size);
	if (!values)
		exit_error();
	current = a->top;
	i = 0;
	while (current)
	{
		values[i] = current->value;
		current = current->next;
		i++;
	}
	i = 0;
	while (i < a->size - 1)
	{
		j = 0;
		while (j < a->size - 1 - i)
		{
			if (values[j] > values[j + 1])
			{
				temp = values[j];
				values[j] = values[j + 1];
				values[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return (values);
}

static int	find_rank(int *sorted, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	assign_indexes(t_stack *a)
{
	int		*sorted;
	t_node	*current;

	sorted = sorted_copy(a);
	current = a->top;
	while (current)
	{
		current->index = find_rank(sorted, a->size, current->value)
		current = current->next;
	}
	free(sorted);
}