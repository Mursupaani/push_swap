/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_stack_details.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:57:11 by anpollan          #+#    #+#             */
/*   Updated: 2025/06/30 14:22:47 by anpollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	update_new_max_value(t_stacks *stacks, int previous_max, int op);
static void	update_new_min_value(t_stacks *stacks, int previous_min, int op);

void	update_stack_details(t_stacks *stacks, int operation)
{
	if (operation == PA)
	{
		if (stacks->stack_b->value < stacks->stack_a_min)
			 stacks->stack_a_min = stacks->stack_b->value;
		if (stacks->stack_b->value > stacks->stack_a_max)
			 stacks->stack_a_max = stacks->stack_b->value;
		if (stacks->stack_b->value == stacks->stack_b_max)
			update_new_max_value(stacks, stacks->stack_b_max, operation);
		if (stacks->stack_b->value == stacks->stack_b_min)
			update_new_min_value(stacks, stacks->stack_b_min, operation);
		stacks->stack_a_len++;
		stacks->stack_b_len--;
	}
	if (operation == PB)
	{
		if (stacks->stack_a->value < stacks->stack_b_min)
			 stacks->stack_b_min = stacks->stack_a->value;
		if (stacks->stack_a->value > stacks->stack_b_max)
			 stacks->stack_b_max = stacks->stack_a->value;
		if (stacks->stack_a->value == stacks->stack_a_max)
			update_new_max_value(stacks, stacks->stack_a_max, operation);
		if (stacks->stack_a->value == stacks->stack_a_min)
			update_new_min_value(stacks, stacks->stack_a_min, operation);
		stacks->stack_a_len--;
		stacks->stack_b_len++;
	}
}

static void	update_new_max_value(t_stacks *stacks, int previous_max, int op)
{
	int		new_max;
	t_node *stack;

	if (op == PA)
		stack = stacks->stack_b;
	else
		stack = stacks->stack_a;
	new_max = INT_MIN;
	while (stack)
	{
		if (stack->value > new_max && stack->value != previous_max)
			new_max = stack->value;
		stack = stack->next;
	}
	if (op == PA)
		stacks->stack_b_max = new_max;
	else
		stacks->stack_a_max = new_max;
}

static void	update_new_min_value(t_stacks *stacks, int previous_min, int op)
{
	int		new_min;
	t_node	*stack;

	if (op == PA)
		stack = stacks->stack_b;
	else
		stack = stacks->stack_a;
	new_min = INT_MAX;
	while (stack)
	{
		if (stack->value < new_min && stack->value != previous_min)
			new_min = stack->value;
		stack = stack->next;
	}
	if (op == PA)
		stacks->stack_b_min = new_min;
	else
		stacks->stack_a_min = new_min;
}
