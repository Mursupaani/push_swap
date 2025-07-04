/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:02:31 by anpollan          #+#    #+#             */
/*   Updated: 2025/06/30 13:58:53 by anpollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*swap_top_two_elements(t_stacks *stacks, int operation)
{
	t_node	*temp;
	t_node	**stack;

	if (operation == SA)
		stack = &stacks->a;
	else
		stack = &stacks->b;
	if (!*stack || !(*stack)->next)
		return (NULL);
	temp = *stack;
	if ((*stack)->next->next)
		(*stack)->next->next->previous = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
	temp->previous = (*stack);
	(*stack)->previous = NULL;
	if (operation == SA)
		return ("sa");
	else if (operation == SB)
		return ("sb");
	else
		return (NULL);
}

char	*push_top_to_other_stack(t_stacks *stacks, int op)
{
	t_node	*temp;
	t_node	**from_stack;
	t_node	**to_stack;

	if (op == PA)
	{
		from_stack = &stacks->b;
		to_stack = &stacks->a;
	}
	else
	{
		from_stack = &stacks->a;
		to_stack = &stacks->b;
	}
	if (!*from_stack || !from_stack || !to_stack)
		return (NULL);
	update_stack_details(stacks, op);
	temp = remove_top_element(from_stack);
	add_node_front(to_stack, temp);
	if (op == PA)
		return ("pa");
	else
		return ("pb");
}

char	*swap_tops_of_both_stacks(t_stacks *stacks)
{
	swap_top_two_elements(stacks, SA);
	swap_top_two_elements(stacks, SB);
	return ("ss");
}
