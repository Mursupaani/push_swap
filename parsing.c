/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:45:07 by anpollan          #+#    #+#             */
/*   Updated: 2025/06/17 11:55:14 by anpollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	pre_parse_input_args(char **args)
{
	while (*args)
	{
		if (!arg_only_digits(*args))
			return (false);
		args++;
	}
	return (true);
}

bool	arg_only_digits(char *arg)
{
	while (*arg)
	{
		if (!ft_isdigit(*arg))
			return (false);
		arg++;
	}
	return (true);
}

bool	parse_input_args(char **args, t_stacks *stacks)
{
	t_node	*temp;
	int		current_value;

	if (!args || !stacks || !&(stacks->stack_a))
		return (false);
	while (*args)
	{
		current_value = ft_atoi(*args);
		if (stacks->stack_a && !value_is_unique(current_value, stacks->stack_a))
			return (false);
		temp = create_new_node(current_value);
		if (!temp)
			return (false);
		if (!add_node_back(&(stacks->stack_a), temp))
			return (false);
		if (current_value > stacks->stack_a_max)
			stacks->stack_a_max = current_value;
		if (current_value < stacks->stack_a_min)
			stacks->stack_a_min = current_value;
		args++;
		stacks->stack_a_len++;
	}
	return (true);
}

bool	value_is_unique(int value, t_node *stack)
{
	t_node	*temp;

	if (!stack)
		return (false);
	temp = stack;
	while (temp)
	{
		if (temp->value == value)
			return (false);
		temp = temp->next;
	}
	return (true);
}
