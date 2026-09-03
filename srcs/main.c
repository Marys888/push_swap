/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msievier <msievier@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 14:32:39 by msievier          #+#    #+#             */
/*   Updated: 2026/09/03 14:32:39 by msievier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_bench	bench;
	char	*strategy_name;
	double	disorder;
	char	*flag;

	if (argc < 2)
		return (0);
	a = (t_stack){NULL, 0};
	b = (t_stack){NULL, 0};
	bench = (t_bench){{0}, 0};
	strategy_name = NULL;
	parse_args(argc, argv, &a);
	if (stack_is_sorted(&a))
	{
		stack_clear(&a);
		return (0);
	}
	assign_indexes(&a);
	disorder = compute_disorder(&a);
	flag = get_flag(argc, argv);
	run_strategy(&a, &b, flag, &bench, &strategy_name);
	if (has_bench_flag(argc, argv))
		print_bench(&bench, disorder, strategy_name);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}