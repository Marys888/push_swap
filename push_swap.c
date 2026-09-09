/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msievier <msievier@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 21:40:02 by msievier          #+#    #+#             */
/*   Updated: 2026/09/09 21:40:02 by msievier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_program(int argc, char **argv, t_node **stack_a)
{
	check_input(argc, argv);
	*stack_a = create_stack(argc, argv);
	check_duplicates(*stack_a);
	assign_index(*stack_a);
}

static void	run_sort(t_node **a, t_node **b, t_options *options, t_bench *bench)
{
	if (options->strategy == SIMPLE)
		sort_simple(a, b, bench);
	else if (options->strategy == MEDIUM)
		sort_medium(a, b, bench);
	else if (options->strategy == COMPLEX)
		sort_complex(a, b, bench);
	else if (options->strategy == ADAPTIVE)
		sort_adaptive(a, b, bench);
}

int	main(int argc, char **argv)
{
	t_node		*stack_a;
	t_node		*stack_b;
	t_options	options;
	t_bench		bench;
	double		disorder;

	init_options(&options);
	init_bench(&bench);
	parse_options(argc, argv, &options);
	init_program(argc, argv, &stack_a);
	disorder = calculate_disorder(stack_a);
	stack_b = NULL;
	if (is_sorted(stack_a))
	{
		free_stack(&stack_a);
		return (0);
	}
	run_sort(&stack_a, &stack_b, &options, &bench);
	if (options.bench)
		print_bench(&bench, disorder, options.strategy);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
