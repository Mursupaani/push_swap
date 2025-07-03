/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_smaller_and_max_values.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:10:13 by anpollan          #+#    #+#             */
/*   Updated: 2025/06/26 18:36:13 by anpollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	*find_smaller_value_from_head(t_node *stack, int value)
// {
// 	static int	smaller_value_and_moves[2];
//
// 	while (stack)
// 	{
// 		if (stack->value < value)
// 		{
// 			smaller_value_and_moves[VAL] = stack->value;
// 			break ;
// 		}
// 		smaller_value_and_moves[POS]++;
// 		stack = stack->next;
// 	}
// 	return (smaller_value_and_moves);
// }
//
// int	*find_smaller_value_from_tail(t_node *stack, int value)
// {
// 	static int	smaller_value_and_moves[2];
// 	t_node	*tail;
//
// 	smaller_value_and_moves[POS] = 1;
// 	tail = find_last_node(stack);
// 	while (tail)
// 	{
// 		if (tail->value < value)
// 		{
// 			smaller_value_and_moves[VAL] = tail->value;
// 			break ;
// 		}
// 		smaller_value_and_moves[POS]++;
// 		tail = tail->previous;
// 	}
// 	return (smaller_value_and_moves);
// }
//
// int	find_max_value_moves_from_head(t_node *stack, int max_value_in_stack)
// {
// 	int	max_value_moves;
//
// 	max_value_moves = 0;
// 	while (stack)
// 	{
// 		if (stack->value == max_value_in_stack)
// 			return (max_value_moves);
// 		stack = stack->next;
// 		max_value_moves++;
// 	}
// 	return (max_value_moves);
// }
//
// int	find_max_value_moves_from_tail(t_node *stack, int max_value_in_stack)
// {
// 	int		max_value_moves;
// 	t_node	*tail;
//
// 	max_value_moves = 1;
// 	tail = find_last_node(stack);
// 	while (tail)
// 	{
// 		if (tail->value == max_value_in_stack)
// 			return (max_value_moves);
// 		max_value_moves++;
// 		tail = tail->previous;
// 	}
// 	return (max_value_moves);
// }
//
//
// int	*store_stack_min_and_max(t_node *stack)
// {
// 	static int	stack_min_max[2];
// 	static bool	been_here_before;
//
// 	if (!been_here_before)
// 	{
// 		stack_min_max[MIN] = stack->value;
// 		stack_min_max[MAX] = stack->value;
// 	}
// 	else if (stack->value < stack_min_max[MIN])
// 		stack_min_max[MIN] = stack->value;
// 	else if (stack->value > stack_min_max[MAX])
// 		stack_min_max[MAX] = stack->value;
// 	return (stack_min_max);
// }
