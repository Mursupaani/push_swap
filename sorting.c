/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:11:36 by anpollan          #+#    #+#             */
/*   Updated: 2025/06/23 17:57:36 by anpollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*find_min_and_max_values(t_node *stack);
void	sort_stack(t_node **stack_a, t_node **stack_b)
{
	int	operation;

	if (!(*stack_b) && is_stack_sorted(*stack_a))
		return ;
	if (!(*stack_a)->next->next || !(*stack_a)->next->next->next)
		sort_max_three(stack_a);
	else
	{
		operation = choose_operation(stack_a, stack_b);
		run_operation(stack_a, stack_b, operation);
	}
	return (sort_stack(stack_a, stack_b));
}

int	choose_operation(t_node **stack_a, t_node **stack_b)
{
	int	*stack_b_min;

	if (!(*stack_b) || !(*stack_b)->next)
		return (PA);
	stack_b_min = find_min_and_max_values(*stack_b);
	return (RR);
}

int	*find_min_and_max_values(t_node *stack)
{
	static int		min_max[2];
	t_node	*temp;

	min_max[0] = stack->value;
	min_max[1] = stack->value;
	temp = stack;
	while (temp)
	{
		if (temp->value < min_max[0])
			min_max[0] = temp->value;
		if (temp->value > min_max[1])
			min_max[1] = temp->value;
		temp = temp->next;
	}
	return (min_max);
}

void	sort_max_three(t_node **stack)
{
	char	*op;
	if (is_stack_sorted(*stack))
		return ;
	if (!(*stack)->next->next)
		op = swap_top_two_elements(stack, SA);
	else if ((*stack)->value > (*stack)->next->value
		&& (*stack)->value > (*stack)->next->next->value)
		op = rotate_stack(stack, RA);
	else if ((*stack)->value > (*stack)->next->next->value)
		op = rotate_stack_reverse(stack, RRA );
	else if ((*stack)->value > (*stack)->next->value)
		op = swap_top_two_elements(stack, SA);
	else
		op = rotate_stack_reverse(stack, RRA);
	ft_printf("%s\n", op);
	return (sort_max_three(stack));
}
