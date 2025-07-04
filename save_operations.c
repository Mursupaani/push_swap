/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 11:29:10 by anpollan          #+#    #+#             */
/*   Updated: 2025/07/04 11:31:53 by anpollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*store_operations_to_array(int operations[], int correct_pos, int len)
{
	if (correct_pos == 0)
	{
		operations[ROT_TIMES] = 0;
		operations[REVROT_TIMES] = 0;
	}
	else
	{
		operations[ROT_TIMES] = correct_pos;
		operations[REVROT_TIMES] = len - correct_pos;
	}
	return (operations);
}

int	*count_op_sum(int a_ops[], int b_ops[])
{
	static int	op_sum[7];

	if (a_ops[OP] == b_ops[OP])
	{
		if (a_ops[OP_TIMES] < b_ops[OP_TIMES])
			op_sum[SAME_OP_TIMES] = a_ops[OP_TIMES];
		else
			op_sum[SAME_OP_TIMES] = b_ops[OP_TIMES];
		op_sum[SAME_OP] = a_ops[OP];
	}
	else
	{
		op_sum[SAME_OP] = NOTHING;
		op_sum[SAME_OP_TIMES] = 0;
	}
	a_ops[OP_TIMES] -= op_sum[SAME_OP_TIMES];
	b_ops[OP_TIMES] -= op_sum[SAME_OP_TIMES];
	op_sum[A_OP] = a_ops[OP];
	op_sum[A_OP_TIMES] = a_ops[OP_TIMES];
	op_sum[B_OP] = b_ops[OP];
	op_sum[B_OP_TIMES] = b_ops[OP_TIMES];
	op_sum[SAME_OP_TIMES] = op_sum[SAME_OP_TIMES];
	op_sum[OP_SUM] = op_sum[SAME_OP_TIMES] + a_ops[OP_TIMES] + b_ops[OP_TIMES];
	return (op_sum);
}

int	*count_best_combination(t_stacks *stacks, int a_ops[], int b_ops[])
{
	int	curr_op_sum[7];
	int	best_op_sum[7];

	curr_op_sum]
}

void	save_best_ops(t_costs *costs)
{
	costs->best_ops[OP_SUM] = costs->cur_tot_ops[OP_SUM];
	costs->best_ops[SAME_OP] = costs->cur_tot_ops[SAME_OP];
	costs->best_ops[SAME_OP_TIMES] = costs->cur_tot_ops[SAME_OP_TIMES];
	costs->best_ops[A_OP] = costs->cur_tot_ops[A_OP];
	costs->best_ops[A_OP_TIMES] = costs->cur_tot_ops[A_OP_TIMES];
	costs->best_ops[B_OP] = costs->cur_tot_ops[B_OP];
	costs->best_ops[B_OP_TIMES] = costs->cur_tot_ops[B_OP_TIMES];
	costs->first_run = false;
}

int	find_correct_val_pos_in_b(t_node *stack, int val_to_add)
{
	int	pos;
	int	cur_pos;
	int	biggest_smaller;

	cur_pos = 0;
	biggest_smaller = INT_MIN;
	while (stack)
	{
		if (val_to_add > stack->val)
		{
			if (stack->val > biggest_smaller)
			{
				biggest_smaller = stack->val;
				pos = cur_pos;
			}
		}
		cur_pos++;
		stack = stack->next;
	}
	return (pos);
}

int	find_correct_val_pos_in_a(t_node *stack, int val_to_add)
{
	int	pos;
	int	cur_pos;
	int	smallest_bigger;

	cur_pos = 0;
	smallest_bigger = INT_MAX;
	while (stack)
	{
		if (val_to_add < stack->val)
		{
			if (stack->val < smallest_bigger)
			{
				smallest_bigger = stack->val;
				pos = cur_pos;
			}
		}
		cur_pos++;
		stack = stack->next;
	}
	return (pos);
}
