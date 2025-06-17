/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:12:08 by anpollan          #+#    #+#             */
/*   Updated: 2025/06/13 18:12:20 by anpollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_node **stack)
{
	t_node	*last;
	t_node	*temp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = find_last_node(*stack);
	if (!last)
		return ;
	temp = *stack;
	(*stack)->next->previous = NULL;
	*stack = (*stack)->next;
	last->next = temp;
	temp->next = NULL;
	temp->previous = last;
}

void	rotate_stack_reverse(t_node **stack)
{
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = find_last_node(*stack);
	if (!last)
		return ;
	last->previous->next = NULL;
	last->previous = NULL;
	last->next = *stack;
	(*stack)->previous = last;
	*stack = last;
}

void	rotate_both_stacks(t_node **stack_a, t_node **stack_b)
{
	if (!stack_a || !stack_b || !*stack_a || !*stack_b
		|| !(*stack_a)->next || !(*stack_b)->next)
		return ;
	rotate_stack(stack_a);
	rotate_stack(stack_b);
}

void	rotate_both_stacks_reverse(t_node **stack_a, t_node **stack_b)
{
	if (!stack_a || !stack_b || !*stack_a || !*stack_b
		|| !(*stack_a)->next || !(*stack_b)->next)
		return ;
	rotate_stack_reverse(stack_a);
	rotate_stack_reverse(stack_b);
}
