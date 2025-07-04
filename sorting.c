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

	stack_a_sorted = is_stack_sorted(stacks->a);
	if (!(stacks->b) && stack_a_sorted)
		return ;
	if (stacks->a_len <= 3 && !stack_a_sorted)
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
	if (stacks->b_len < 2 && !push_all_to_a)
		run_operation_and_update_stacks(stacks, PB);
	else if (push_all_to_a && stacks->b)
		find_best_operation_to_a(stacks);
	else if (push_all_to_a && !stacks->b)
		run_operation_and_update_stacks(stacks, RA);
	else
		find_best_operation_to_b(stacks);
	return (0);
}

void	find_best_operation_to_b(t_stacks *s)
{
	t_costs	c;
	t_node	*tmp;

	c.first_run = true;
	c.cur_a_pos = 0;
	tmp = s->a;
	while (tmp)
	{
		c.cur_a_ops = count_val_to_top(s->a, tmp->val, s->a_len, &c.cur_a_pos);
		if (tmp->val < s->b_min || tmp->val > s->b_max)
			c.cur_b_ops = count_val_to_top(s->b, s->b_max, s->b_len, NULL);
		else
			c.cur_b_ops = count_correct_pos(tmp->val, s->b, s->b_len, 'b');
		if (!c.cur_a_ops || !c.cur_b_ops)
			error_exit(s, &c);
		c.cur_tot_ops = count_op_sum(c.cur_a_ops, c.cur_b_ops);
		if (c.first_run || c.cur_tot_ops[OP_SUM] < c.best_ops[OP_SUM])
			save_best_ops(&c);
		tmp = tmp->next;
		c.cur_a_pos++;
		free_operation_memory(&c);
	}
	run_best_ops(s, c.best_ops, 'b');
}

void	find_best_operation_to_a(t_stacks *s)
{
	t_costs	c;
	t_node	*tmp;

	c.first_run = true;
	c.cur_b_pos = 0;
	tmp = s->b;
	while (tmp)
	{
		c.cur_b_ops = count_val_to_top(s->b, tmp->val, s->b_len, &c.cur_b_pos);
		if (tmp->val < s->a_min || tmp->val > s->a_max)
			c.cur_a_ops = count_val_to_top(s->a, s->a_min, s->a_len, NULL);
		else
			c.cur_a_ops = count_correct_pos(tmp->val, s->a, s->a_len, 'a');
		if (!c.cur_a_ops || !c.cur_b_ops)
			error_exit(s, &c);
		c.cur_tot_ops = count_op_sum(c.cur_a_ops, c.cur_b_ops);
		if (c.first_run || c.cur_tot_ops[OP_SUM] < c.best_ops[OP_SUM])
			save_best_ops(&c);
		tmp = tmp->next;
		c.cur_b_pos++;
		free_operation_memory(&c);
	}
	run_best_ops(s, c.best_ops, 'a');
}

void	run_best_ops(t_stacks *stacks, int best_ops[], char stack)
{
	while (best_ops[SAME_OP_TIMES]--)
	{
		if (best_ops[SAME_OP] == ROTATE)
			run_operation_and_update_stacks(stacks, RR);
		else if (best_ops[SAME_OP] == REVERSE_ROTATE)
			run_operation_and_update_stacks(stacks, RRR);
	}
	while (best_ops[A_OP_TIMES]--)
	{
		if (best_ops[A_OP] == ROTATE)
			run_operation_and_update_stacks(stacks, RA);
		else
			run_operation_and_update_stacks(stacks, RRA);
	}
	while (best_ops[B_OP_TIMES]--)
	{
		if (best_ops[B_OP] == ROTATE)
			run_operation_and_update_stacks(stacks, RB);
		else
			run_operation_and_update_stacks(stacks, RRB);
	}
	if (stack == 'b')
		run_operation_and_update_stacks(stacks, PB);
	else if (stack == 'a')
		run_operation_and_update_stacks(stacks, PA);
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

int	*count_val_to_top(t_node *stack, int val, int stack_len, int *pos)
{
	int	*operations;
	int	cur_pos;

	operations = (int *)malloc(sizeof(int) * 2);
	if (!operations)
		return (NULL);
	if (!pos)
		cur_pos = find_val_pos(stack, val);
	else
		cur_pos = *pos;
	store_operations_to_array(operations, cur_pos, stack_len);
	return (operations);
}

int	find_val_pos(t_node *stack, int val)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->val == val)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (pos);
}

void	sort_max_three_in_a_stack(t_stacks *stacks)
{
	if (!stacks->a || !stacks->a->next)
		return ;
	if (is_stack_sorted(stacks->a))
		return ;
	if (!stacks->a->next->next)
		run_operation_and_update_stacks(stacks, SA);
	else if (stacks->a->val > stacks->a->next->val
		&& stacks->a->val > stacks->a->next->next->val)
		run_operation_and_update_stacks(stacks, RA);
	else if (stacks->a->val > stacks->a->next->next->val)
		run_operation_and_update_stacks(stacks, RRA);
	else if (stacks->a->val > stacks->a->next->val)
		run_operation_and_update_stacks(stacks, SA);
	else
		run_operation_and_update_stacks(stacks, RRA);
	return (sort_max_three_in_a_stack(stacks));
}

int	*count_correct_pos(int val, t_node *stack, int len, char op_stack)
{
	int	*operations;
	int	correct_pos;

	operations = (int *)malloc(sizeof(int) * 2);
	if (!operations)
		return (NULL);
	if (op_stack == 'b')
		correct_pos = find_correct_val_pos_in_b(stack, val);
	else
		correct_pos = find_correct_val_pos_in_a(stack, val);
	store_operations_to_array(operations, correct_pos, len);
	return (operations);
}

int	*store_operations_to_array(int operations[], int correct_pos, int len)
{
	if (correct_pos == 0)
	{
		operations[OP] = NOTHING;
		operations[OP_TIMES] = 0;
	}
	else if (correct_pos <= len / 2)
	{
		operations[OP] = ROTATE;
		operations[OP_TIMES] = correct_pos;
	}
	else
	{
		operations[OP] = REVERSE_ROTATE;
		operations[OP_TIMES] = len - correct_pos;
	}
	return (operations);
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
