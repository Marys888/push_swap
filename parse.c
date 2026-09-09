/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cathrinevarlamova <cathrinevarlamova@student.42.fr>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-09-06 19:46:34 by cathrinevarlamova #+#    #+#             */
/*   Updated: 2026-09-06 19:46:34 by cathrinevarlamova ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_options(t_options *options)
{
	options->strategy = ADAPTIVE;
	options->bench = 0;
}

void	parse_options(int argc, char **argv, t_options *options)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "--simple") == 0)
			options->strategy = SIMPLE;
		if (ft_strcmp(argv[i], "--medium") == 0)
			options->strategy = MEDIUM;
		if (ft_strcmp(argv[i], "--complex") == 0)
			options->strategy = COMPLEX;
		if (ft_strcmp(argv[i], "--adaptive") == 0)
			options->strategy = ADAPTIVE;
		if (ft_strcmp(argv[i], "--bench") == 0)
			options->bench = 1;
		i++;
	}
}

void	check_input(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "--simple") == 0
			|| ft_strcmp(argv[i], "--medium") == 0
			|| ft_strcmp(argv[i], "--complex") == 0
			|| ft_strcmp(argv[i], "--adaptive") == 0
			|| ft_strcmp(argv[i], "--bench") == 0)
		{
			i++;
			continue ;
		}
		if (!is_number(argv[i]))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}

void	check_duplicates(t_node *stack)
{
	t_node	*current;
	t_node	*compare;

	current = stack;
	while (current)
	{
		compare = current->next;
		while (compare)
		{
			if (current->content == compare->content)
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			compare = compare->next;
		}
		current = current->next;
	}
}
