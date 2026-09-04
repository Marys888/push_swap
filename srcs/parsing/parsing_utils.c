/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msievier <msievier@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 17:58:38 by msievier          #+#    #+#             */
/*   Updated: 2026/08/29 17:58:38 by msievier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
		i++;
	return (i);
}

void	free_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

static long	str_to_long_checked(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if(str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		exit_error();
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			exit_error();
		result = result * 10 + (str[i] - '0');
		if (result * sign > INT_MAX	|| result * sign < INT_MIN)
			exit_error();
		i++;
	}
	return (result * sign);
}

int	*tokens_to_values(char  **tokens, int n)
{
	int	*values;
	int	i;

	values = malloc(sizeof(int) * n);
	if (!values)
		exit_error();
	i = 0;
	while (i < n)
	{
		values[i] = (int)str_to_long_checked(tokens[i]);
		i++;
	}
	return (values);
}