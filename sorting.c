/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:11:36 by anpollan          #+#    #+#             */
/*   Updated: 2025/07/04 11:31:59 by anpollan         ###   ########.fr       */
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

void	rotate_a_to_sort(t_stacks *stacks)
{
	int	a_min_pos;
	int	times_to_run;

	a_min_pos = find_val_pos(stacks->a, stacks->a_min);
	if (a_min_pos <= stacks->a_len / 2)
	{
		times_to_run = a_min_pos;
		while (times_to_run--)
			run_operation_and_update_stacks(stacks, RA);
	}
	else
	{
		times_to_run = stacks->a_len - a_min_pos;
		while (times_to_run--)
			run_operation_and_update_stacks(stacks, RRA);
	}

}
