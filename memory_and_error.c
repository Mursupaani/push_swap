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
	free_dynamic_args(stacks->args, stacks->dynarg);
	free_operation_memory(costs);
	free_stacks_memory(stacks);
}

void	free_operation_memory(t_costs *costs)
{
	if (costs && costs->cur_a_ops)
	{
		free(costs->cur_a_ops);
		costs->cur_a_ops = NULL;
	}
	if (costs && costs->cur_b_ops)
	{
		free(costs->cur_b_ops);
		costs->cur_b_ops = NULL;
	}
}

void	free_stacks_memory(t_stacks *stacks)
{
	t_node	*temp;

	while (stacks->a)
	{
		temp = stacks->a->next;
		free(stacks->a);
		stacks->a = NULL;
		stacks->a = temp;
	}
	while (stacks->b)
	{
		temp = stacks->b->next;
		free(stacks->b);
		stacks->b = NULL;
		stacks->b = temp;
	}
	free(stacks);
}

void	free_dynamic_args(char **args, bool dynarg)
{
	int		i;

	if (dynarg && args)
	{
		i = 0;
		while (args[i])
			free(args[i++]);
		free(args);
		args = NULL;
	}
}
