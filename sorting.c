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
#include <climits>

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
		choose_operation(stack_a, stack_b, stack_a_sorted);
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
		operation = find_best_operation(*stack_a, *stack_b, stack_b_min_max);
	if (operation == PB)
		stack_b_min_max = store_stack_min_and_max(*stack_a);
	return (operation);
}

int	find_best_operation(t_node *stack_a, t_node *stack_b, int b_min_max[])
{
	int	operation[2];
	int	temp_operation[2];

	operation[OPERATION] = INT_MAX;
	operation[TIMES_TO_RUN] = INT_MIN;
	while (stack_a)
	{
		if (stack_a->value < b_min_max[MIN])
			count_best_operation_for_new_min(stack_a, stack_b, b_min_max, temp_operation);
		if (temp_operation[TIMES_TO_RUN] < operation[TIMES_TO_RUN])
		{
			temp_operation[OPERATION] = operation[OPERATION];
			temp_operation[TIMES_TO_RUN] = operation[TIMES_TO_RUN];
		}
	}
	return (0);
}

int	*count_best_operation_for_new_min(t_node *stack_a, t_node *stack_b, int b_min_max[], int op[])
{
	static int	min_operations[4];
	int			head_min_ops;
	int			tail_min_ops;

	if (stack_a->value < b_min_max[MIN])
	{
		head_min_ops = find_max_value_moves_from_head(stack_b, b_min_max[MAX]);
		tail_min_ops = find_max_value_moves_from_tail(stack_b, b_min_max[MAX]);
	}
	if (head_min_ops < min_operations[HEAD_NUM_OF_OPS])
		min_operations[HEAD_NUM_OF_OPS] = head_min_ops;
	if (tail_min_ops < min_operations[TAIL_NUM_OF_OPS])
		min_operations[TAIL_NUM_OF_OPS] = tail_min_ops;
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
