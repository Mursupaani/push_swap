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

	print_detailed_stacks(stacks);
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
	if (stacks->stack_b_len < 2 && !stack_a_sorted)
		run_operation_and_update_stacks(stacks, PB);
	else if (stack_a_sorted && stacks->stack_b)
		run_operation_and_update_stacks(stacks, PA);
	else if (!stack_a_sorted && !stacks->stack_b && is_stack_sorted(stacks->stack_a->next))
			run_operation_and_update_stacks(stacks, RA);
	else
		find_best_operation(stacks);
	return (0);
}

int	find_best_operation(t_stacks *stacks)
{
	t_costs	costs;
	t_node	*temp;

	costs.first_run = true;
	costs.current_a_pos = 0;
	temp = stacks->stack_a;
	while (temp)
	{
		costs.current_a_operations = calculate_max_to_top(stacks->stack_a, temp->value, stacks->stack_a_len);
		if (temp->value < stacks->stack_b_min || temp->value > stacks->stack_b_max)
			costs.current_b_operations = calculate_max_to_top(stacks->stack_b, stacks->stack_b_max, stacks->stack_b_len);
		else
			costs.current_b_operations = calculate_correct_position_in_b(temp->value, stacks->stack_b, stacks->stack_b_len);
		costs.current_total_operations = calculate_operation_sum(costs.current_a_operations, costs.current_b_operations);
		if (costs.first_run || costs.current_total_operations[OPERATION_SUM] < costs.best_operations[OPERATION_SUM])
			save_best_operations(&costs);
		temp = temp->next;
		costs.current_a_pos++;
	}
	run_best_operations(stacks, costs.best_operations);
	return (0);
}

// void	find_best_operation_to_push_to_a(t_stacks *stacks)
// {
//
// }

void	run_best_operations(t_stacks *stacks, int best_operations[])
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
	run_operation_and_update_stacks(stacks, PB);
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

int	*calculate_max_to_top(t_node *stack, int max_value, int stack_len)
{
	static int	operations[2];
	int			max_position;

	max_position = find_max_value_pos(stack, max_value);
	if (max_position == 0)
	{
		operations[OPERATION] = NOTHING;
		operations[TIMES_TO_RUN] = max_position;
	}
	else if (max_position <= stack_len / 2)
	{
		operations[OPERATION] = ROTATE;
		operations[TIMES_TO_RUN] = max_position;
	}
	else
	{
		operations[OPERATION] = REVERSE_ROTATE;
		operations[TIMES_TO_RUN] = stack_len - max_position;
	}
	return (operations);
}

int	find_max_value_pos(t_node *stack, int max_value)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->value == max_value)
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

int	*calculate_value_to_top(int stack_len, int pos_in_stack)
{
	static int	operations[2];

	if (pos_in_stack == 0)
	{
		operations[TIMES_TO_RUN] = 0;
		operations[OPERATION] = NOTHING;
	}
	else if (pos_in_stack <= stack_len / 2)
	{
		operations[TIMES_TO_RUN] = pos_in_stack;
		operations[OPERATION] = ROTATE;
	}
	else
	{
		operations[TIMES_TO_RUN] = stack_len - pos_in_stack;
		operations[OPERATION] = REVERSE_ROTATE;
	}
	return (operations);
}

int	*calculate_correct_position_in_b(int value_to_add, t_node *stack_to_append, int stack_len)
{
	static int	operations[2];
	int			correct_position;

	correct_position = find_correct_value_pos_in_b(stack_to_append, value_to_add);
	if (correct_position == 0)
	{
		operations[OPERATION] = NOTHING;
		operations[TIMES_TO_RUN] = 0;
	}
	if (correct_position <= stack_len / 2)
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

int *calculate_operation_sum(int a_operations[], int b_operations[])
{
	static int	operation_sum[7];
	int	common_operations;
	int	a_operation_times;
	int	b_operation_times;
	
	a_operation_times = a_operations[TIMES_TO_RUN];
	b_operation_times = b_operations[TIMES_TO_RUN];
	common_operations = 0;
	if (a_operations[OPERATION] == b_operations[OPERATION])
	{
		if (a_operation_times < b_operation_times)
			common_operations = a_operation_times;
		else
			common_operations = b_operation_times;
		operation_sum[COMMON_OPERATION] = a_operations[OPERATION];
	}
	else
		operation_sum[COMMON_OPERATION] = NOTHING;
	a_operation_times -= common_operations;
	b_operation_times -= common_operations;
	operation_sum[A_OPERATION] = a_operations[OPERATION];
	operation_sum[A_OPERATION_TIMES] = a_operation_times;
	operation_sum[B_OPERATION] = b_operations[OPERATION];
	operation_sum[B_OPERATION_TIMES] = b_operation_times;
	operation_sum[OPERATION_SUM] = common_operations + a_operation_times + b_operation_times + 1;
	operation_sum[COMMON_OPERATION_TIMES] = common_operations;
	return (operation_sum);
}
