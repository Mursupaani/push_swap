/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 20:29:07 by anpollan          #+#    #+#             */
/*   Updated: 2025/06/13 20:57:01 by anpollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*remove_top_element(t_node **stack)
{
	t_node	*temp;

	if (!stack || !*stack)
		return (NULL);
	temp = *stack;
	if ((*stack)->next)
	{
		*stack = (*stack)->next;
		(*stack)->previous = NULL;
	}
	else
		*stack = NULL;
	temp->next = NULL;
	temp->previous = NULL;
	return (temp);
}

t_node	*remove_bottom_element(t_node *stack)
{
	t_node	*last;

	if (!stack)
		return (NULL);
	last = find_last_node(stack);
	if (last->previous)
		last->previous->next = NULL;
	last->next = NULL;
	last->previous = NULL;
	return (last);
}
