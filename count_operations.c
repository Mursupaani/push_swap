/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 11:25:26 by anpollan          #+#    #+#             */
/*   Updated: 2025/07/04 11:27:05 by anpollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		c.cur_tot_ops = count_best_combination(c.cur_a_ops, c.cur_b_ops);
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
		c.cur_tot_ops = count_best_combination(c.cur_a_ops, c.cur_b_ops);
		if (c.first_run || c.cur_tot_ops[OP_SUM] < c.best_ops[OP_SUM])
			save_best_ops(&c);
		tmp = tmp->next;
		c.cur_b_pos++;
		free_operation_memory(&c);
	}
	run_best_ops(s, c.best_ops, 'a');
}

int	*count_val_to_top(t_node *stack, int val, int stack_len, int *pos)
{
	int	*operations;
	int	cur_pos;

	operations = (int *)malloc(sizeof(int) * 4);
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

int	*count_correct_pos(int val, t_node *stack, int len, char op_stack)
{
	int	*operations;
	int	correct_pos;

	operations = (int *)malloc(sizeof(int) * 4);
	if (!operations)
		return (NULL);
	if (op_stack == 'b')
		correct_pos = find_correct_val_pos_in_b(stack, val);
	else
		correct_pos = find_correct_val_pos_in_a(stack, val);
	store_operations_to_array(operations, correct_pos, len);
	return (operations);
}
