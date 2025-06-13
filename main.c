/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:32:15 by anpollan          #+#    #+#             */
/*   Updated: 2025/06/13 11:59:45 by anpollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

static bool	arg_only_digits(char *arg);
static bool	pre_parse_input_args(int argc, char *argv[]);
static bool	parse_input_args(int argc, char *argv[], t_node **stack_a);

int	main(int argc, char *argv[])
{
	t_node		*stack_a;
	t_node		*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || !pre_parse_input_args(argc, argv))
	{
		ft_printf("Please input argument integers separated by spaces\n");
		return (1);
	}
	if (!parse_input_args(argc, argv, &stack_a))
	{
		ft_printf("There was an error parsing arguments.\n");
		return (1);
	}
	print_stack(stack_a);
	return (0);
}

static bool	pre_parse_input_args(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!arg_only_digits(argv[i]))
			return (false);
		i++;
	}
	return (true);
}

static bool	arg_only_digits(char *arg)
{
	while (*arg)
	{
		if (!ft_isdigit(*arg))
			return (false);
		arg++;
	}
	return (true);
}

static bool	parse_input_args(int argc, char *argv[], t_node **stack_a)
{
	t_node	*temp;
	int	i;

	i = 1;
	while (i < argc)
	{
		temp = create_new_node(ft_atoi(argv[i++]));
		if (!temp)
			return (false);
		if (!add_node_back(stack_a, temp))
			return (false);
	}
	return (true);
}
