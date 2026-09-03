/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msievier <msievier@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 18:12:32 by msievier          #+#    #+#             */
/*   Updated: 2026/08/29 18:12:32 by msievier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	check_dublicates(int *values, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (values[i] == values[j])
				exit_error();
			j++;
		}
		i++;
	}
}

void	fill_stack(t_stack a, int *values, int n)
{
	t_node	*node;
	int		i;

	check_dublicates(values, n);
	a->top = NULL;
	a->size = 0;
	i = n - 1;
	while (i >= 0)
	{
		node = stack_new_node[i];
		if (!node)
			exit_error();
		stack_push_front(a, node);
		i--;
	}
}