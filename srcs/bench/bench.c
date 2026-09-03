/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msievier <msievier@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 13:17:45 by msievier          #+#    #+#             */
/*   Updated: 2026/09/03 13:17:45 by msievier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_disorder(double disorder)
{
	int	percent_int;
	int	percent_frac;

	percent_int = (int)(disorder * 100);
	percent_frac = (int)(disorder * 10000) % 100;
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(percent_int, 2);
	ft_putstr_fd(".", 2);
	if (percent_frac < 10)
		ft_putstr_fd("0", 2);
	ft_putnbr_fd(percent_frac, 2);
	ft_putstr_fd("%\n", 2);
}

static void	print_op_counts(t_bench *bench)
{
	const char	*names[11] = {"sa", "sb", "ss", "pa", "pb",
			"ra", "rb", "rr", "rra", "rrb", "rrr"};
	int			i;

	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(bench->total, 2);
	ft_putstr_fd("\n[bench] ", 2);
	i = 0;
	while (i < 11)
	{
		ft_putstr_fd(names[i], 2);
		ft_putstr_fd(": ", 2);
		ft_putnbr_fd(bench->counts[i], 2);
		if (i < 10)
			ft_putstr_fd("  ", 2);
		i++;
	}
	ft_putstr_fd("\n", 2);
}

void	print_bench(t_bench *bench, double disorder, char *strategy_name)
{
	print_disorder(disorder);
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd(strategy_name, 2);
	ft_putstr_fd("\n", 2);
	print_op_counts(bench);
}