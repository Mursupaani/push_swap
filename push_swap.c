/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:33:25 by anpollan          #+#    #+#             */
/*   Updated: 2025/06/30 14:24:14 by anpollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stacks *stacks)
{
	if (!pre_parse_input_args(stacks->args) || !parse_input_args(stacks))
		error_exit(stacks, NULL);
	if (is_stack_sorted(stacks->a))
		return ;
	sort_stack(stacks);
}

bool	is_stack_sorted(t_node *stack)
{
	t_node	*temp;

	if (!stack)
		return (false);
	temp = stack;
	while (temp->next)
	{
		if (temp->val > temp->next->val)
			return (false);
		temp = temp->next;
	}
	return (true);
}

void	run_operation_and_update_stacks(t_stacks *stacks, int operation)
{
	char	*op;

	if (operation == SA || operation == SB)
		op = swap_top_two_elements(stacks, operation);
	else if (operation == SS)
		op = swap_tops_of_both_stacks(stacks);
	else if (operation == PA || operation == PB)
		op = push_top_to_other_stack(stacks, operation);
	else if (operation == RA || operation == RB)
		op = rotate_stack(stacks, operation);
	else if (operation == RR)
		op = rotate_both_stacks(stacks);
	else if (operation == RRA)
		op = rotate_stack_reverse(stacks, operation);
	else if (operation == RRB)
		op = rotate_stack_reverse(stacks, operation);
	else
		op = rotate_both_stacks_reverse(stacks);
	ft_printf("%s\n", op);
}
