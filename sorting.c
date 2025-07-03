/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:11:36 by anpollan          #+#    #+#             */
/*   Updated: 2025/06/30 21:36:08 by anpollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stacks *stacks)
{
	bool	stack_a_sorted;

	stack_a_sorted = is_stack_sorted(stacks->stack_a);
	if (!(stacks->stack_b) && stack_a_sorted)
		return ;
	if (stacks->stack_a_len <= 3 && !stack_a_sorted)
		sort_max_three_in_a_stack(stacks);
	else
		choose_operation(stacks, stack_a_sorted);
	return (sort_stack(stacks));
}

int	choose_operation(t_stacks *stacks, bool stack_a_sorted)
{
	static bool	push_all_to_a;

	if (stack_a_sorted)
		push_all_to_a = true;
	if (stacks->stack_b_len < 2 && !push_all_to_a)
		run_operation_and_update_stacks(stacks, PB);
	else if (push_all_to_a && stacks->stack_b)
		find_best_operation_to_a(stacks);
	else if (push_all_to_a && !stacks->stack_b)
		run_operation_and_update_stacks(stacks, RA);
	else
		find_best_operation_to_b(stacks);
	return (0);
}

void	find_best_operation_to_b(t_stacks *stacks)
{
	t_costs	costs;
	t_node	*temp;

	costs.first_run = true;
	costs.current_a_pos = 0;
	temp = stacks->stack_a;
	while (temp)
	{
		costs.current_a_operations = calculate_value_to_top(stacks->stack_a, temp->value, stacks->stack_a_len, &costs.current_a_pos);
		if (temp->value < stacks->stack_b_min || temp->value > stacks->stack_b_max)
			costs.current_b_operations = calculate_value_to_top(stacks->stack_b, stacks->stack_b_max, stacks->stack_b_len, NULL);
		else
			costs.current_b_operations = calculate_correct_position(temp->value, stacks->stack_b, stacks->stack_b_len, 'b');
		if (!costs.current_a_operations || !costs.current_b_operations)
			error_exit(stacks, &costs);
		costs.current_total_operations = calculate_operation_sum(costs.current_a_operations, costs.current_b_operations);
		if (costs.first_run || costs.current_total_operations[OPERATION_SUM] < costs.best_operations[OPERATION_SUM])
			save_best_operations(&costs);
		temp = temp->next;
		costs.current_a_pos++;
		free_operation_memory(&costs);
	}
	run_best_operations(stacks, costs.best_operations, 'b');
}


void	find_best_operation_to_a(t_stacks *stacks)
{
	t_costs	costs;
	t_node	*temp;

	costs.first_run = true;
	costs.current_b_pos = 0;
	temp = stacks->stack_b;
	while (temp)
	{
		costs.current_b_operations = calculate_value_to_top(stacks->stack_b, temp->value, stacks->stack_b_len, &costs.current_b_pos);
		if (temp->value < stacks->stack_a_min || temp->value > stacks->stack_a_max)
			costs.current_a_operations = calculate_value_to_top(stacks->stack_a, stacks->stack_a_min, stacks->stack_a_len, NULL);
		else
			costs.current_a_operations = calculate_correct_position(temp->value, stacks->stack_a, stacks->stack_a_len, 'a');
		if (!costs.current_a_operations || !costs.current_b_operations)
			error_exit(stacks, &costs);
		costs.current_total_operations = calculate_operation_sum(costs.current_a_operations, costs.current_b_operations);
		if (costs.first_run || costs.current_total_operations[OPERATION_SUM] < costs.best_operations[OPERATION_SUM])
			save_best_operations(&costs);
		temp = temp->next;
		costs.current_b_pos++;
		free_operation_memory(&costs);
	}
	run_best_operations(stacks, costs.best_operations, 'a');
}

void	run_best_operations(t_stacks *stacks, int best_operations[], char stack)
{
	while (best_operations[COMMON_OPERATION_TIMES]--)
	{
		if (best_operations[COMMON_OPERATION] == ROTATE)
			run_operation_and_update_stacks(stacks, RR);
		else if (best_operations[COMMON_OPERATION] == REVERSE_ROTATE)
			run_operation_and_update_stacks(stacks, RRR);
	}
	while (best_operations[A_OPERATION_TIMES]--)
	{
		if (best_operations[A_OPERATION] == ROTATE)
			run_operation_and_update_stacks(stacks, RA);
		else
			run_operation_and_update_stacks(stacks, RRA);
	}
	while (best_operations[B_OPERATION_TIMES]--)
	{
		if (best_operations[B_OPERATION] == ROTATE)
			run_operation_and_update_stacks(stacks, RB);
		else
			run_operation_and_update_stacks(stacks, RRB);
	}
	if (stack == 'b')
		run_operation_and_update_stacks(stacks, PB);
	else if (stack == 'a')
		run_operation_and_update_stacks(stacks, PA);
}

void	save_best_operations(t_costs *costs)
{
	costs->best_operations[OPERATION_SUM] = costs->current_total_operations[OPERATION_SUM];
	costs->best_operations[COMMON_OPERATION] = costs->current_total_operations[COMMON_OPERATION];
	costs->best_operations[COMMON_OPERATION_TIMES] = costs->current_total_operations[COMMON_OPERATION_TIMES];
	costs->best_operations[A_OPERATION] = costs->current_total_operations[A_OPERATION];
	costs->best_operations[A_OPERATION_TIMES] = costs->current_total_operations[A_OPERATION_TIMES];
	costs->best_operations[B_OPERATION] = costs->current_total_operations[B_OPERATION];
	costs->best_operations[B_OPERATION_TIMES] = costs->current_total_operations[B_OPERATION_TIMES];
	costs->first_run = false;
}

int	*calculate_value_to_top(t_node *stack, int value, int stack_len, int *pos)
{
	int	*operations;
	int	position;

	operations = (int *)malloc(sizeof(int) * 2);
	if (!operations)
		return (NULL);
	if (!pos)
		position = find_value_pos(stack, value);
	else
		position = *pos;
	store_operations_to_array(operations, position, stack_len);
	return (operations);
}

int	find_value_pos(t_node *stack, int value)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->value == value)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (pos);
}

void	sort_max_three_in_a_stack(t_stacks *stacks)
{
	if (!stacks->stack_a || !stacks->stack_a->next)
		return ;
	if (is_stack_sorted(stacks->stack_a))
		return ;
	if (!stacks->stack_a->next->next)
		run_operation_and_update_stacks(stacks, SA);
	else if (stacks->stack_a->value > stacks->stack_a->next->value
		&& stacks->stack_a->value > stacks->stack_a->next->next->value)
		run_operation_and_update_stacks(stacks, RA);
	else if (stacks->stack_a->value > stacks->stack_a->next->next->value)
		run_operation_and_update_stacks(stacks, RRA);
	else if (stacks->stack_a->value > stacks->stack_a->next->value)
		run_operation_and_update_stacks(stacks, SA);
	else
		run_operation_and_update_stacks(stacks, RRA);
	return (sort_max_three_in_a_stack(stacks));
}

int	*calculate_correct_position(int value_to_add, t_node *stack_to_append, int stack_len, char stack)
{
	int	*operations;
	int	correct_position;

	operations = (int *)malloc(sizeof(int) * 2);
	if (!operations)
		return (NULL);
	if (stack == 'b')
		correct_position = find_correct_value_pos_in_b(stack_to_append, value_to_add);
	else
		correct_position = find_correct_value_pos_in_a(stack_to_append, value_to_add);
	store_operations_to_array(operations, correct_position, stack_len);
	return (operations);
}

int	*store_operations_to_array(int operations[], int correct_position, int stack_len)
{
	if (correct_position == 0)
	{
		operations[OPERATION] = NOTHING;
		operations[TIMES_TO_RUN] = 0;
	}
	else if (correct_position <= stack_len / 2)
	{
		operations[OPERATION] = ROTATE;
		operations[TIMES_TO_RUN] = correct_position;
	}
	else
	{
		operations[OPERATION] = REVERSE_ROTATE;
		operations[TIMES_TO_RUN] = stack_len - correct_position;
	}
	return (operations);
}

int	find_correct_value_pos_in_b(t_node *stack, int value_to_add)
{
	int	position;
	int	current_position;
	int	biggest_smaller;

	current_position = 0;
	biggest_smaller = INT_MIN;
	while (stack)
	{
		if (value_to_add > stack->value)
		{
			if (stack->value > biggest_smaller)
			{
				biggest_smaller = stack->value;
				position = current_position;
			}
		}
		current_position++;
		stack = stack->next;
	}
	return (position);
}

int	find_correct_value_pos_in_a(t_node *stack, int value_to_add)
{
	int	position;
	int	current_position;
	int	smallest_bigger;

	current_position = 0;
	smallest_bigger = INT_MAX;
	while (stack)
	{
		if (value_to_add < stack->value)
		{
			if (stack->value < smallest_bigger)
			{
				smallest_bigger = stack->value;
				position = current_position;
			}
		}
		current_position++;
		stack = stack->next;
	}
	return (position);
}

int *calculate_operation_sum(int a_operations[], int b_operations[])
{
	static int	operation_sum[7];
	
	if (a_operations[OPERATION] == b_operations[OPERATION])
	{
		if (a_operations[TIMES_TO_RUN] < b_operations[TIMES_TO_RUN])
			operation_sum[COMMON_OPERATION_TIMES] = a_operations[TIMES_TO_RUN];
		else
			operation_sum[COMMON_OPERATION_TIMES]= b_operations[TIMES_TO_RUN];
		operation_sum[COMMON_OPERATION] = a_operations[OPERATION];
	}
	else
	{
		operation_sum[COMMON_OPERATION] = NOTHING;
		operation_sum[COMMON_OPERATION_TIMES] = 0;
	}
	a_operations[TIMES_TO_RUN] -= operation_sum[COMMON_OPERATION_TIMES];
	b_operations[TIMES_TO_RUN] -= operation_sum[COMMON_OPERATION_TIMES];
	operation_sum[A_OPERATION] = a_operations[OPERATION];
	operation_sum[A_OPERATION_TIMES] = a_operations[TIMES_TO_RUN];
	operation_sum[B_OPERATION] = b_operations[OPERATION];
	operation_sum[B_OPERATION_TIMES] = b_operations[TIMES_TO_RUN];
	operation_sum[COMMON_OPERATION_TIMES] = operation_sum[COMMON_OPERATION_TIMES];
	operation_sum[OPERATION_SUM] = operation_sum[COMMON_OPERATION_TIMES] + a_operations[TIMES_TO_RUN] + b_operations[TIMES_TO_RUN];
	return (operation_sum);
}
