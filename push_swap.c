/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:33:25 by anpollan          #+#    #+#             */
/*   Updated: 2025/06/23 17:34:01 by anpollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_node **stack_a, t_node **stack_b, char **args, bool dynarg)
{
	if (!pre_parse_input_args(args) || !parse_input_args(args, stack_a))
		error_exit(stack_a, stack_b, args, dynarg);
	if (is_stack_sorted(*stack_a))
		return ;
	sort_stack(stack_a, stack_b);
}

void	run_operation(t_node **stack_a, t_node **stack_b, int operation)
{
	char	*op;

	if (operation == SA)
		op = swap_top_two_elements(stack_a, operation);
	else if (operation == SB)
		op = swap_top_two_elements(stack_b, operation);
	else if (operation == SS)
		op = swap_tops_of_both_stacks(stack_a, stack_b);
	else if (operation == PA)
		op = push_top_to_other_stack(stack_b, stack_a, operation);
	else if (operation == PB)
		op = push_top_to_other_stack(stack_a, stack_b, operation);
	else if	(operation == RA)
		op = rotate_stack(stack_a, operation);
	else if	(operation == RB)
		op = rotate_stack(stack_b, operation);
	else if (operation == RR)
		op = rotate_both_stacks(stack_a, stack_b);
	else if (operation == RRA)
		op = rotate_stack_reverse(stack_a, operation);
	else if (operation == RRB )
		op = rotate_stack_reverse(stack_b, operation);
	else
		op = rotate_both_stacks_reverse(stack_a, stack_b);
	ft_printf("%s\n", op);
}

bool	is_stack_sorted(t_node *stack)
{
	t_node	*temp;

	if (!stack)
		return (false);
	temp = stack;
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			return (false);
		temp = temp->next;
	}
	return(true);
}

bool	is_stack_reverse_sorted(t_node *stack)
{
	t_node	*last;

	if (!stack)
		return (false);
	last = (stack);
	while (last->previous)
	{
		if (last->value < last->previous->value)
			return (false);
		last = last->previous;
	}
	return (true);
}
