/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msievier <msievier@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 21:17:07 by msievier          #+#    #+#             */
/*   Updated: 2026/09/09 21:17:09 by msievier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h> 
# include <unistd.h>

# define SIMPLE 1
# define MEDIUM 2
# define COMPLEX 3
# define ADAPTIVE 4

typedef struct s_node
{
	int				content;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_options
{
	int	strategy;
	int	bench;
}	t_options;

typedef struct s_bench
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
}	t_bench;

//stack:
t_node	*new_node(int content);
void	add_last_node(t_node **stack, t_node *new);
t_node	*create_stack(int argc, char **argv);
void	assign_index(t_node *stack);

//stack_utils:
int		ft_atoi(const char *nptr);
void	print_stack(t_node *stack);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	free_stack(t_node **stack);

//operations:
void	sa(t_node **stack, t_bench *bench);
void	sb(t_node **stack, t_bench *bench);
void	ss(t_node **stack_a, t_node **stack_b, t_bench *bench);
void	pb(t_node **stack_a, t_node **stack_b, t_bench *bench);
void	pa(t_node **stack_a, t_node **stack_b, t_bench *bench);
void	ra(t_node **stack, t_bench *bench);
void	rb(t_node **stack, t_bench *bench);
void	rr(t_node **stack_a, t_node **stack_b, t_bench *bench);
void	rra(t_node **stack, t_bench *bench);
void	rrb(t_node **stack, t_bench *bench);
void	rrr(t_node **stack_a, t_node **stack_b, t_bench *bench);

//sort:
// int		get_strategy(int argc, char **argv);
int		is_sorted(t_node *stack);

//simple:
int		find_min(t_node *stack);
int		stack_size(t_node *stack);
int		find_position(t_node *stack, int value);
void	sort_simple(t_node **a, t_node **b, t_bench *bench);

//medium:
void	sort_medium(t_node **a, t_node **b, t_bench *bench);

//complex:
void	sort_complex(t_node **a, t_node **b, t_bench *bench);

//adaptive:
void	sort_adaptive(t_node **a, t_node **b, t_bench *bench);

//parse:
void	init_options(t_options *options);
void	parse_options(int argc, char **argv, t_options *options);
void	check_input(int argc, char **argv);
void	check_duplicates(t_node *stack);

//parse_utils:
int		ft_strcmp(char *s1, char *s2);
int		is_number(char *str);

//bench:
void	init_bench(t_bench *bench);
void	print_bench(t_bench *bench, double disorder, int strategy);

//disorder:
double	calculate_disorder(t_node *stack);

#endif
