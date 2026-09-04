/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msievier <msievier@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 18:28:40 by msievier          #+#    #+#             */
/*   Updated: 2026/08/29 18:28:40 by msievier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include "libft.h"

/* # include "../libft/libft.h" */

# define SIMPLE_THRESHOLD 0.2
# define MEDIUM_THRESHOLD 0.5

typedef enum e_op
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}	t_op;

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

typedef struct s_bench
{
	int	counts[11];
	int	total;
}	t_bench;

void	parse_args(int argc, char **argv, t_stack *a);
int		count_tokens(char **tokens);
void	free_tokens(char **tokens);
int		*tokens_to_values(char **tokens, int n);
void	fill_stack(t_stack *a, int *values, int n);

void	exit_error(void);

t_node	*stack_new_node(int value);
void	stack_push_front(t_stack *s, t_node *node);
int		stack_size(t_stack *s);
int		stack_is_sorted(t_stack *s);
int		stack_get_min_index(t_stack *s);
void	stack_clear(t_stack *s);

void	op_sa(t_stack *a);
void	op_sb(t_stack *b);
void	op_ss(t_stack *a, t_stack *b);
void	op_pa(t_stack *a, t_stack *b);
void	op_pb(t_stack *a, t_stack *b);
void	op_ra(t_stack *a);
void	op_rb(t_stack *b);
void	op_rr(t_stack *a, t_stack *b);
void	op_rra(t_stack *a);
void	op_rrb(t_stack *b);
void	op_rrr(t_stack *a, t_stack *b);
void	do_op(t_op op, t_stack *a, t_stack *b, t_bench *bench);

void	assign_indexes(t_stack *a);

double	compute_disorder(t_stack *a);

void	sort_simple(t_stack *a, t_stack *b, t_bench *bench);
void	sort_medium(t_stack *a, t_stack *b, t_bench *bench);
void	sort_complex(t_stack *a, t_stack *b, t_bench *bench);
void	sort_adaptive(t_stack *a, t_stack *b, t_bench *bench,
			char **strategy_name);

char	*get_flag(int argc, char **argv);
int		has_bench_flag(int argc, char **argv);
void	run_strategy(t_stack *a, t_stack *b, char *flag,
			t_bench *bench, char **name);

void	print_bench(t_bench *bench, double disorder, char *strategy_name);

#endif