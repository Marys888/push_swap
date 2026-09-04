/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msievier <msievier@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 14:24:14 by msievier          #+#    #+#             */
/*   Updated: 2026/08/22 14:24:14 by msievier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_flag(const char *arg)
{
	return (ft_strncmp(arg, "--", 2) == 0 && ft_strlen(arg) > 2);
}

static char	*join_arguments(int argc, char **argv)
{
	char	*joined;
	char	*temp;
	int		i;

	joined = ft_strdup("");
	i = 1;
	while (i < argc)
	{
		if (!is_flag(argv[i]))
		{
			temp = joined;
			joined = ft_strjoin(joined, argv[i]);
			free(temp);
			temp = joined;
			joined  = ft_strjoin(joined, " ");
			free(temp);
		}
		i++;
	}
	return (joined);
}

void	parse_args(int argc, char **argv, t_stack *a)
{
	char	*joined;
	char	**tokens;
	int		*values;
	int		count;

	if (argc < 2)
		return;
	joined  = join_arguments(argc, argv);
	tokens  = ft_split(joined, ' ');
	free(joined);
	if (!tokens)
		exit_error();
	count = count_tokens(tokens);
	if (count == 0)
		exit_error();
	values = tokens_to_values(tokens, count);
	free_tokens(tokens);
	fill_stack(a, values, count);
	free(values);
}
