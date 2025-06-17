/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:33:25 by anpollan          #+#    #+#             */
/*   Updated: 2025/06/11 13:33:47 by anpollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_stack_sorted(t_node *stack)
{
	t_node	*temp;

	if (!stack)
		return (false);
	temp = stack;
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			return (false);
		temp = temp->next;
	}
	return(true);
}

void	print_error_and_exit(t_node *stack_a, t_node *stack_b, char **args)
{
	t_node	*temp;
	int		i;

	while (stack_a)
	{
		temp = stack_a->next;
		free(stack_a);
		stack_a = temp;
	}
	while (stack_b)
	{
		temp = stack_b->next;
		free(stack_b);
		stack_b = temp;
	}
	if (args)
	{
		i = 0;
		while (args[i])
			free(args[i++]);
		free(args);
	}
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
