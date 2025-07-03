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

void	error_exit(t_stacks *stacks, t_costs *costs)
{
	ft_putstr_fd("Error\n", 2);
	free_memory(stacks, costs);
	exit(EXIT_FAILURE);
}

void	free_memory(t_stacks *stacks, t_costs *costs)
{
	t_node	*temp;
	int		i;

	while (stacks->stack_a)
	{
		temp = stacks->stack_a->next;
		free(stacks->stack_a);
		stacks->stack_a = NULL;
		stacks->stack_a = temp;
	}
	while (stacks->stack_b)
	{
		temp = stacks->stack_b->next;
		free(stacks->stack_b);
		stacks->stack_b = NULL;
		stacks->stack_b = temp;
	}
	if (costs && costs->current_a_operations)
		free(costs->current_a_operations);
	if (costs && costs->current_b_operations)
		free(costs->current_b_operations);
	if (stacks->dynarg && stacks->args)
	{
		i = 0;
		while (stacks->args[i])
			free(stacks->args[i++]);
		free(stacks->args);
		stacks->args = NULL;
	}
	free(stacks);
	exit(1);
}
