/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:12:08 by anpollan          #+#    #+#             */
/*   Updated: 2025/06/23 16:38:35 by anpollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*rotate_stack(t_node **stack, int op)
{
	t_node	*last;
	t_node	*temp;

	if (!stack || !*stack || !(*stack)->next)
		return (NULL);
	last = find_last_node(*stack);
	if (!last)
		return (NULL);
	temp = *stack;
	(*stack)->next->previous = NULL;
	*stack = (*stack)->next;
	last->next = temp;
	temp->next = NULL;
	temp->previous = last;
	if	(op == RA)
		return ("ra");
	else
		return ("rb");
}

char	*rotate_stack_reverse(t_node **stack, int operation)
{
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return (NULL);
	last = find_last_node(*stack);
	if (!last)
		return (NULL);
	last->previous->next = NULL;
	last->previous = NULL;
	last->next = *stack;
	(*stack)->previous = last;
	*stack = last;
	if (operation == RRA)
		return ("rra");
	else
		return ("rrb");
}

char	*rotate_both_stacks(t_stacks *stacks)
{
	if (!stacks->stack_a || !stacks->stack_b
		|| !stacks->stack_a->next || !stacks->stack_b->next)
		return (NULL);
	rotate_stack(&stacks->stack_a, RA);
	rotate_stack(&stacks->stack_b, RB);
	return ("rr");
}

char	*rotate_both_stacks_reverse(t_stacks *stacks)
{
	if (!stacks->stack_a || !stacks->stack_b
		|| !stacks->stack_a->next || !stacks->stack_b->next)
		return (NULL);
	rotate_stack_reverse(&stacks->stack_a, RRA);
	rotate_stack_reverse(&stacks->stack_b, RRB);
	return ("rrr");
}
