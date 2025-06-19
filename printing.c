/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:15:38 by anpollan          #+#    #+#             */
/*   Updated: 2025/06/13 19:42:30 by anpollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_node *stack)
{
	if (!stack)
	{
		ft_printf("Empty\n");
		return;
	}
	while (stack)
	{
		ft_printf("%d", stack->value);
		if (stack->next)
			ft_printf(" ");
		else
			ft_printf("\n");
		stack = stack->next;
	}
}

void	print_stack_reverse(t_node *stack)
{
	t_node	*last;

	if (!stack)
	{
		ft_printf("Empty\n");
		return;
	}
	last = find_last_node(stack);
	while (last)
	{
		ft_printf("%d", last->value);
		if (last->previous)
			ft_printf(" ");
		else
			ft_printf("\n");
		last = last->previous;
	}
}

void	print_detailed_stacks(t_node *stack_a, t_node *stack_b)
{
	ft_printf("Stack a:\t ");
	print_stack(stack_a);
	ft_printf("Stack a rev:\t ");
	print_stack_reverse(stack_a);
	ft_printf("Stack b:\t ");
	print_stack(stack_b);
	ft_printf("Stack b rev:\t ");
	print_stack_reverse(stack_b);
	ft_printf("Is stack_a sorted: %d\n", is_stack_sorted(stack_a));
	ft_printf("Is stack_b sorted: %d\n", is_stack_sorted(stack_b));
}
