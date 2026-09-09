/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cavarlam <cavarlam@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 16:45:53 by cavarlam          #+#    #+#             */
/*   Updated: 2026/08/26 17:03:46 by cavarlam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_node		*stack_a;
	t_node		*stack_b;
	t_options	options;
	t_bench		bench;
	double		disorder;

	init_options(&options);
	init_bench(&bench);
	check_input(argc, argv);
	parse_options(argc, argv, &options);
	stack_a = create_stack(argc, argv);
	check_duplicates(stack_a);
	assign_index(stack_a);
	disorder = calculate_disorder(stack_a);
	stack_b = NULL;
	if (is_sorted(stack_a))
	{
		free_stack(&stack_a);
		return (0);
	}
	if (options.strategy == SIMPLE)
		sort_simple(&stack_a, &stack_b, &bench);
	else if (options.strategy == MEDIUM)
		sort_medium(&stack_a, &stack_b, &bench);
	else if (options.strategy == COMPLEX)
		sort_complex(&stack_a, &stack_b, &bench);
	else if (options.strategy == ADAPTIVE)
		sort_adaptive(&stack_a, &stack_b, &bench);
	if (options.bench)
		print_bench(&bench, disorder, options.strategy);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}