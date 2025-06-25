/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:02:31 by anpollan          #+#    #+#             */
/*   Updated: 2025/06/23 16:25:49 by anpollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*swap_top_two_elements(t_node **stack, int operation)
{
	t_node	*temp;

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

char	*push_top_to_other_stack(t_node **from_stack, t_node **to_stack, int op)
{
	t_node	*temp;

	if (!*from_stack || !from_stack || !to_stack)
		return (NULL);
	temp = remove_top_element(from_stack);
	add_node_front(to_stack, temp);
	if (op == PA)
		return ("pa");
	else
		return ("pb");
}

char	*swap_tops_of_both_stacks(t_node **stack_a, t_node **stack_b)
{
	swap_top_two_elements(stack_a, SA);
	swap_top_two_elements(stack_b, SB);
	return ("ss");
}
