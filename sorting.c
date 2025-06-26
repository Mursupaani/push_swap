/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:11:36 by anpollan          #+#    #+#             */
/*   Updated: 2025/06/26 18:38:27 by anpollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_node **stack_a, t_node **stack_b)
{
	int		operation;
	bool	stack_a_sorted;

	stack_a_sorted = is_stack_sorted(*stack_a);
	if (!(*stack_b) && stack_a_sorted)
		return ;
	if ((!(*stack_a)->next->next || !(*stack_a)->next->next->next) && !stack_a_sorted)
		sort_max_three(stack_a);
	else
	{
		operation = choose_operation(stack_a, stack_b, stack_a_sorted);
		run_operation(stack_a, stack_b, operation);
	}
	return (sort_stack(stack_a, stack_b));
}

int	choose_operation(t_node **stack_a, t_node **stack_b, bool stack_a_sorted)
{
	static int	*stack_b_min_max;
	int	operation;

	if ((!(*stack_b) || !(*stack_b)->next) && !stack_a_sorted)
		operation = PB;
	else if (*stack_b && is_stack_reverse_sorted(*stack_b)
		&& stack_a_sorted)
		operation = PA;
	else if (!stack_a_sorted && !*stack_b && is_stack_sorted((*stack_a)->next))
		operation = RA;
	else
		operation = count_best_operation(*stack_a, *stack_b, stack_b_min_max);
	if (operation == PB)
		stack_b_min_max = store_stack_min_and_max(*stack_a);
	return (operation);
}

int	count_best_operation(t_node *stack_a, t_node *stack_b, int b_min_max[])
{
	int	min_operations;
	int	temp_min_operations;
	int	value_from_head;
	int	value_from_tail;

	min_operations = 0;
	temp_min_operations = 0;
	while (stack_a)
	{
		if (stack_a->value < b_min_max[MIN])
		{
			value_from_head = find_max_value_moves_from_head(stack_b, b_min_max[MAX]);
			value_from_tail = find_max_value_moves_from_tail(stack_b, b_min_max[MAX]);
			if (value_from_head < value_from_tail)
				temp_min_operations = value_from_head;
			else
				temp_min_operations = value_from_tail;
			if (!min_operations)
				min_operations = temp_min_operations;
		}
	}
	return (min_operations);
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
