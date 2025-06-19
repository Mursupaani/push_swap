/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:32:15 by anpollan          #+#    #+#             */
/*   Updated: 2025/06/13 20:57:58 by anpollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_node		*stack_a;
	t_node		*stack_b;
	bool		dynarg;
	char		**args;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
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
	push_swap(&stack_a, &stack_b, args, dynarg);
	free_memory(&stack_a, &stack_b, args, dynarg);
	return (0);
}

