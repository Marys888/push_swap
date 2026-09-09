/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cathrinevarlamova <cathrinevarlamova@student.42.fr>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-09-07 19:18:05 by cathrinevarlamova #+#    #+#             */
/*   Updated: 2026-09-07 19:18:05 by cathrinevarlamova ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	check_swap(t_node **a, t_node **b, char *op)
{
	t_node	*tmp;

	if (ft_strcmp(op, "sa") == 0 && *a && (*a)->next)
	{
		tmp = (*a)->next;
		(*a)->next = tmp->next;
		tmp->next = *a;
		*a = tmp;
	}
	else if (ft_strcmp(op, "sb") == 0 && *b && (*b)->next)
	{
		tmp = (*b)->next;
		(*b)->next = tmp->next;
		tmp->next = *b;
		*b = tmp;
	}
	else if (ft_strcmp(op, "ss") == 0)
	{
		check_swap(a, b, "sa");
		check_swap(a, b, "sb");
	}
}

static void	check_push(t_node **a, t_node **b, char *op)
{
	t_node	*tmp;

	if (ft_strcmp(op, "pa") == 0 && *b)
	{
		tmp = *b;
		*b = tmp->next;
		tmp->next = *a;
		*a = tmp;
	}
	else if (ft_strcmp(op, "pb") == 0 && *a)
	{
		tmp = *a;
		*a = tmp->next;
		tmp->next = *b;
		*b = tmp;
	}
}

static void	check_rotate(t_node **a, t_node **b, char *op)
{
	t_node	*first;
	t_node	*last;

	if (ft_strcmp(op, "ra") == 0 && *a && (*a)->next)
	{
		first = *a;
		*a = first->next;
		last = *a;
		while (last->next)
			last = last->next;
		first->next = NULL;
		last->next = first;
	}
	else if (ft_strcmp(op, "rb") == 0 && *b && (*b)->next)
	{
		first = *b;
		*b = first->next;
		last = *b;
		while (last->next)
			last = last->next;
		first->next = NULL;
		last->next = first;
	}
}

static void	check_reverse(t_node **a, t_node **b, char *op)
{
	t_node	*prev;
	t_node	*last;

	if ((ft_strcmp(op, "rra") == 0 || ft_strcmp(op, "rrr") == 0)
		&& *a && (*a)->next)
	{
		prev = NULL;
		last = *a;
		while (last->next)
		{
			prev = last;
			last = last->next;
		}
		prev->next = NULL;
		last->next = *a;
		*a = last;
	}
	if ((ft_strcmp(op, "rrb") == 0 || ft_strcmp(op, "rrr") == 0)
		&& *b && (*b)->next)
	{
		prev = NULL;
		last = *b;
		while (last->next)
		{
			prev = last;
			last = last->next;
		}
		prev->next = NULL;
		last->next = *b;
		*b = last;
	}
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	char	op[4];

	if (argc < 2)
		return (0);
	a = create_stack(argc, argv);
	b = NULL;
	while (scanf("%3s", op) == 1)
	{
		check_swap(&a, &b, op);
		check_push(&a, &b, op);
		check_rotate(&a, &b, op);
		check_reverse(&a, &b, op);
	}
	if (is_sorted(a) && !b)
		printf("OK\n");
	else
		printf("KO\n");
	free_stack(&a);
	free_stack(&b);
	return (0);
}