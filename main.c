/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:32:15 by anpollan          #+#    #+#             */
/*   Updated: 2025/06/30 14:33:34 by anpollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stacks	*initialize_stacks(char **args, bool dynarg);

int	main(int argc, char *argv[])
{
	t_stacks	*stacks;
	bool		dynarg;
	char		**args;

	if (argc == 1 || !argv || argv[1][0] == '\0')
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	else if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		dynarg = true;
	}
	else
	{
		args = &argv[1];
		dynarg = false;
	}
	stacks = initialize_stacks(args, dynarg);
	push_swap(stacks);
	free_memory(stacks, NULL);
	return (0);
}

static t_stacks	*initialize_stacks(char **args, bool dynarg)
{
	t_stacks	*stacks;

	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (!stacks)
		error_exit(NULL, NULL);
	stacks->stack_a = NULL;
	stacks->stack_a_len = 0;
	stacks->stack_a_max = INT_MIN;
	stacks->stack_a_min = INT_MAX;
	stacks->stack_b = NULL;
	stacks->stack_b_len = 0;
	stacks->stack_b_max = INT_MIN;
	stacks->stack_b_min = INT_MAX;
	stacks->args = args;
	stacks->dynarg = dynarg;
	return (stacks);
}
