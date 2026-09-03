/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msievier <msievier@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 18:26:32 by msievier          #+#    #+#             */
/*   Updated: 2026/09/02 18:26:32 by msievier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_op_name(t_op op)
{
	if (op == SA)
		ft_putstr_fd("sa\n", 1);
	else if (op == SB)
		ft_putstr_fd("sb\n", 1);
	else if (op == SS)
		ft_putstr_fd("ss\n", 1);
	else if (op == PA)
		ft_putstr_fd("pa\n", 1);
	else if (op == PB)
		ft_putstr_fd("pb\n", 1);
	else if (op == RA)
		ft_putstr_fd("ra\n", 1);
	else if (op == RB)
		ft_putstr_fd("rb\n", 1);
	else if (op == RR)
		ft_putstr_fd("rr\n", 1);
	else if (op == RRA)
		ft_putstr_fd("rra\n", 1);
	else if (op == RRB)
		ft_putstr_fd("rrb\n", 1);
	else if (op == RRR)
		ft_putstr_fd("rrr\n", 1);
}

static void	execute_op(t_op op, t_stack *a, t_stack *b)
{
	if (op == SA)
		op_sa(a);
	else if (op == SB)
		op_sb(b);
	else if (op == SS)
		op_ss(a, b);
	else if (op == PA)
		op_pa(a, b);
	else if (op == PB)
		op_pb(a, b);
	else if (op == RA)
		op_ra(a);
	else if (op == RB)
		op_rb(b);
	else if (op == RR)
		op_rr(a, b);
	else if (op == RRA)
		op_rra(a);
	else if (op == RRB)
		op_rrb(b);
	else if (op == RRR)
		op_rrr(a, b);
}

void	do_op(t_op op, t_stack *a, t_stack *b, t_bench *bench)
{
	execute_op(op, a, b);
	print_op_name(op);
	bench->counts[op]++;
	bench->total++;
}