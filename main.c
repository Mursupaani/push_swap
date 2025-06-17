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
	char		**args;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	else if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv;
	if (!pre_parse_input_args(args)
		|| !parse_input_args(args, &stack_a))
		print_error_and_exit(stack_a, stack_b, args);
	print_error_and_exit(stack_a, stack_b, args);
	ft_printf("Stack a:\t ");
	print_stack(stack_a);
	ft_printf("Stack a rev:\t ");
	print_stack_reverse(stack_a);
	ft_printf("Stack b:\t ");
	print_stack(stack_b);
	ft_printf("Stack b rev:\t ");
	print_stack_reverse(stack_b);
	ft_printf("Is stack sorted: %d\n", is_stack_sorted(stack_a));
	rotate_stack(&stack_a);
	ft_printf("Stack a:\t ");
	print_stack(stack_a);
	ft_printf("Stack a rev:\t ");
	print_stack_reverse(stack_a);
	ft_printf("Stack b:\t ");
	print_stack(stack_b);
	ft_printf("Stack b rev:\t ");
	print_stack_reverse(stack_b);
	ft_printf("Is stack sorted: %d\n", is_stack_sorted(stack_a));
	return (0);
}

