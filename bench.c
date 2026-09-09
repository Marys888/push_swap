/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msievier <msievier@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 21:14:57 by msievier          #+#    #+#             */
/*   Updated: 2026/09/09 21:19:53 by msievier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_bench(t_bench *bench)
{
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
	bench->total = 0;
}

static void	print_strategy(int strategy, double disorder)
{
	if (strategy == SIMPLE)
		ft_putstr_fd("Strategy: Simple (O(n^2))\n", 2);
	else if (strategy == MEDIUM)
		ft_putstr_fd("Strategy: Medium (O(n*sqrt(n)))\n", 2);
	else if (strategy == COMPLEX)
		ft_putstr_fd("Strategy: Complex (O(n log n))\n", 2);
	else if (disorder < 0.2)
		ft_putstr_fd("Strategy: Adaptive -> Simple (O(n^2))\n", 2);
	else if (disorder < 0.5)
		ft_putstr_fd("Strategy: Adaptive -> Medium (O(n*sqrt(n)))\n", 2);
	else
		ft_putstr_fd("Strategy: Adaptive -> Complex (O(n log n))\n", 2);
}

void	print_operation_counts(t_bench *bench)
{
	ft_putstr_fd("sa: ", 2);
	ft_putnbr_fd(bench->sa, 2);
	ft_putstr_fd("\nsb: ", 2);
	ft_putnbr_fd(bench->sb, 2);
	ft_putstr_fd("\nss: ", 2);
	ft_putnbr_fd(bench->ss, 2);
	ft_putstr_fd("\npa: ", 2);
	ft_putnbr_fd(bench->pa, 2);
	ft_putstr_fd("\npb: ", 2);
	ft_putnbr_fd(bench->pb, 2);
	ft_putstr_fd("\nra: ", 2);
	ft_putnbr_fd(bench->ra, 2);
	ft_putstr_fd("\nrb: ", 2);
	ft_putnbr_fd(bench->rb, 2);
	ft_putstr_fd("\nrr: ", 2);
	ft_putnbr_fd(bench->rr, 2);
	ft_putstr_fd("\nrra: ", 2);
	ft_putnbr_fd(bench->rra, 2);
	ft_putstr_fd("\nrrb: ", 2);
	ft_putnbr_fd(bench->rrb, 2);
	ft_putstr_fd("\nrrr: ", 2);
	ft_putnbr_fd(bench->rrr, 2);
	ft_putstr_fd("\n", 2);
}

void	print_bench(t_bench *bench, double disorder, int strategy)
{
	ft_putstr_fd("Disorder: ", 2);
	ft_putnbr_fd((int)(disorder * 100), 2);
	ft_putstr_fd("%\n", 2);
	print_strategy(strategy, disorder);
	ft_putstr_fd("Total operations: ", 2);
	ft_putnbr_fd(bench->total, 2);
	ft_putstr_fd("\n", 2);
	print_operation_counts(bench);
}
