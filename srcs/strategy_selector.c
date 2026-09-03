/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_selector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msievier <msievier@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 15:27:05 by msievier          #+#    #+#             */
/*   Updated: 2026/09/03 15:27:05 by msievier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*get_flag(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--simple", 9) == 0)
			return ("--simple");
		if(ft_strncmp(argv[i], "--medium", 9) == 0)
			return ("--medium");
		if(ft_strncmp(argv[i], "--complex", 10) == 0)
			return ("--complex");
		if(ft_strncmp(argv[i], "--adaptive", 11) == 0)
			return ("--adaptive");
		i++;
	}
	return ("--adaptive");
}

int	has_bench_flag(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--bench", 8) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	run_strategy(t_stack *a, t_stack *b, char *flag, t_bench *bench, char **name)
{
	if (ft_strncmp(flag, "--simple", 9) == 0)
	{
		name = "Simple / O(n^2)";
		sort_simple(a, b, bench);
	}
	else if (ft_strncmp(flag, "--medium", 9) == 0)
	{
		name = "Medium / O(n*sqrt(n))";
		sort_medium(a, b, bench);
	}
	else if (ft_strncmp(flag, "--complex", 10) == 0)
	{
		name = "Complex / O(n log n)";
		sort_complex(a, b, bench);
	}
	else
		sort_adaptive(a, b, bench, name);
}