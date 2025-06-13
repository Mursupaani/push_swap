/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:02:31 by anpollan          #+#    #+#             */
/*   Updated: 2025/06/13 20:47:13 by anpollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_top_two_elements(t_node **stack)
{
	t_node	*temp;

	if (!*stack || !(*stack)->next)
		return ;
	temp = *stack;
	if ((*stack)->next->next)
		(*stack)->next->next->previous = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
	temp->previous = (*stack);
	(*stack)->previous = NULL;
}

void	push_top_to_other_stack(t_node **from_stack, t_node **to_stack)
{
	t_node	*temp;

	if (!*from_stack || !from_stack || !to_stack)
		return ;
	temp = remove_top_element(from_stack);
	add_node_back(to_stack, temp);
}
// void	push_top_to_other_stack(t_node **from_stack, t_node **to_stack)
// {
// 	t_node	*temp;
// 	t_node	*temp2;
//
// 	if (!*from_stack || !from_stack || !to_stack)
// 		return ;
// 	temp = *from_stack;
// 	if ((*from_stack)->next)
// 	{
// 		(*from_stack)->next->previous = NULL;
// 		*from_stack = (*from_stack)->next;
// 	}
// 	else
// 		*from_stack = NULL;
// 	if (*to_stack)
// 	{
// 		temp2 = *to_stack;
// 		*to_stack = temp;
// 		(*to_stack)->next = temp2;
// 	}
// 	else
// 	{
// 		*to_stack = temp;
// 		(*to_stack)->next = NULL;
// 	}
// }
