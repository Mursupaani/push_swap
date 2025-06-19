/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_and_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:53:34 by anpollan          #+#    #+#             */
/*   Updated: 2025/06/18 11:54:06 by anpollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(t_node **stack_a, t_node **stack_b, char **args, bool dynarg)
{
	ft_putstr_fd("Error\n", 2);
	free_memory(stack_a, stack_b, args, dynarg);
	exit(EXIT_FAILURE);
}

void	free_memory(t_node **stack_a, t_node **stack_b, char **args, bool dynarg)
{
	t_node	*temp;
	int		i;

	while (*stack_a)
	{
		temp = (*stack_a)->next;
		free(*stack_a);
		*stack_a = NULL;
		*stack_a = temp;
	}
	while (*stack_b)
	{
		temp = (*stack_b)->next;
		free(*stack_b);
		*stack_b = NULL;
		*stack_b = temp;
	}
	if (dynarg && args)
	{
		i = 0;
		while (args[i])
			free(args[i++]);
		free(args);
		args = NULL;
	}
}
