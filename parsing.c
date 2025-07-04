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
	int i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (false);
		arg++;
	}
	return (true);
}

bool	parse_input_args(t_stacks *stacks)
{
	t_node	*temp;
	int		i;
	int		current_val;

	i = 0;
	if (!stacks || !stacks->args || !&(stacks->a))
		return (false);
	while (stacks->args[i])
	{
		current_val = ft_atoi_error_exit(stacks->args[i++], stacks);
		if (stacks->a && !val_is_unique(current_val, stacks->a))
			return (false);
		temp = create_new_node(current_val);
		if (!temp)
			return (false);
		if (!add_node_back(&(stacks->a), temp))
			return (false);
		if (current_val > stacks->a_max)
			stacks->a_max = current_val;
		if (current_val < stacks->a_min)
			stacks->a_min = current_val;
		stacks->a_len++;
	}
	free_dynamic_args(stacks);
	return (true);
}

bool	val_is_unique(int val, t_node *stack)
{
	t_node	*temp;

	if (!stack)
		return (false);
	temp = stack;
	while (temp)
	{
		if (temp->val == val)
			return (false);
		temp = temp->next;
	}
	return (true);
}

int	ft_atoi_error_exit(const char *nptr, t_stacks *stacks)
{
	int			sign;
	long int	result;

	sign = 1;
	result = 0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
		if (ft_isdigit(*nptr))
			error_exit(stacks, NULL);
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result *= 10;
		result += *nptr - '0';
		nptr++;
	}
	if (result > INT_MAX || result < INT_MIN)
		error_exit(stacks, NULL);
	return (sign * result);
}
