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
	free_dynamic_args(stacks);
	free_operation_memory(costs);
	free_stacks_memory(stacks);
	exit(1);
}

void	free_operation_memory(t_costs *costs)
{
	if (costs && costs->current_a_operations)
	{
		free(costs->current_a_operations);
		costs->current_a_operations = NULL;
	}
	if (costs && costs->current_b_operations)
	{
		free(costs->current_b_operations);
		costs->current_b_operations = NULL;
	}
}

void	free_stacks_memory(t_stacks *stacks)
{
	t_node	*temp;

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
	free(stacks);
}

void free_dynamic_args(t_stacks *stacks)
{
	int		i;
	char	**temp;

	if (stacks->dynarg && stacks->args)
	{
		i = 0;
		temp = stacks->args; 
		while (temp[i])
			free(temp[i++]);
		free(temp);
		temp = NULL;
	}
}
