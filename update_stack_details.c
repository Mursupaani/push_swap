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

static void	update_new_max_val(t_stacks *stacks, int previous_max, int op);
static void	update_new_min_val(t_stacks *stacks, int previous_min, int op);
static void	update_pa(t_stacks *stacks, int operation);
static void	update_pb(t_stacks *stacks, int operation);

void	update_stack_details(t_stacks *stacks, int operation)
{
	if (operation == PA)
		update_pa(stacks, operation);
	if (operation == PB)
		update_pb(stacks, operation);
}

static void	update_pa(t_stacks *stacks, int operation)
{
	if (stacks->b->val < stacks->a_min)
		stacks->a_min = stacks->b->val;
	if (stacks->b->val > stacks->a_max)
		stacks->a_max = stacks->b->val;
	if (stacks->b->val == stacks->b_max)
		update_new_max_val(stacks, stacks->b_max, operation);
	if (stacks->b->val == stacks->b_min)
		update_new_min_val(stacks, stacks->b_min, operation);
	stacks->a_len++;
	stacks->b_len--;
}

static void	update_pb(t_stacks *stacks, int operation)
{
	if (stacks->a->val < stacks->b_min)
		stacks->b_min = stacks->a->val;
	if (stacks->a->val > stacks->b_max)
		stacks->b_max = stacks->a->val;
	if (stacks->a->val == stacks->a_max)
		update_new_max_val(stacks, stacks->a_max, operation);
	if (stacks->a->val == stacks->a_min)
		update_new_min_val(stacks, stacks->a_min, operation);
	stacks->a_len--;
	stacks->b_len++;
}

static void	update_new_max_val(t_stacks *stacks, int previous_max, int op)
{
	int		new_max;
	t_node	*stack;

	if (op == PA)
		stack = stacks->b;
	else
		stack = stacks->a;
	new_max = INT_MIN;
	while (stack)
	{
		if (stack->val > new_max && stack->val != previous_max)
			new_max = stack->val;
		stack = stack->next;
	}
	if (op == PA)
		stacks->b_max = new_max;
	else
		stacks->a_max = new_max;
}

static void	update_new_min_val(t_stacks *stacks, int previous_min, int op)
{
	int		new_min;
	t_node	*stack;

	if (op == PA)
		stack = stacks->b;
	else
		stack = stacks->a;
	new_min = INT_MAX;
	while (stack)
	{
		if (stack->val < new_min && stack->val != previous_min)
			new_min = stack->val;
		stack = stack->next;
	}
	if (op == PA)
		stacks->b_min = new_min;
	else
		stacks->a_min = new_min;
}
