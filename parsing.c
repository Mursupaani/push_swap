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

bool	parse_input_args(char **args, t_node **stack_a)
{
	t_node	*temp;

	if (!args)
		return (false);
	while (*args)
	{
		temp = create_new_node(ft_atoi(*args));
		if (!temp)
			return (false);
		if (!add_node_back(stack_a, temp))
			return (false);
		args++;
	}
	return (true);
}

// bool	value_is_unique(char *value, int value_index, char *argv[])
// {
// 	int	i;
//
// 	if (!value || !argv)
// 		return (false);
// 	i = 0;
// 	while (argv[i])
// 	{
// 		if (i == value_index)
// 			i++;
// 	}
// 	return (true);
// }
