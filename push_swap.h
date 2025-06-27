/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:25:54 by anpollan          #+#    #+#             */
/*   Updated: 2025/06/26 18:37:07 by anpollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*previous;
}	t_node;

typedef struct s_structs
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		stack_a_len;
	int		stack_b_len;
}	t_stucts;

enum	Value_and_position
{
	VAL,
	POS
}	;

enum	Min_and_max
{
	MIN,
	MAX
}	;

enum	Operation_to_run_and_times_to_run
{
	OPERATION,
	TIMES_TO_RUN
}	;

enum	Moves_from_head_and_moves_from_tail
{
	HEAD_OPS,
	HEAD_NUM_OF_OPS,
	TAIL_OPS,
	TAIL_NUM_OF_OPS
}	;

enum	Operations
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}	;

// FIXME: No need for this?
int		*find_min_and_max_values(t_node *stack);

void	print_detailed_stacks(t_node *stack_a, t_node *stack_b);
void	push_swap(t_node **stack_a, t_node **stack_b, char **args, bool dynarg);
bool	pre_parse_input_args(char **args);
bool	arg_only_digits(char *arg);
bool	parse_input_args(char **args, t_node **stack_a);
t_node	*create_new_node(int value);
t_node	*find_last_node(t_node *head);
t_node	*add_node_back(t_node **head, t_node *node_to_add);
t_node	*add_node_front(t_node **head, t_node *node_to_add);
void	print_stack(t_node *stack);
void	print_stack_reverse(t_node *stack);
char	*swap_top_two_elements(t_node **stack, int operation);
char	*swap_tops_of_both_stacks(t_node **stack_a, t_node **stack_b);
char	*push_top_to_other_stack(t_node **from_stack, t_node **to_stack, int op);
t_node	*remove_top_element(t_node **stack);
t_node	*remove_bottom_element(t_node *stack);
char	*rotate_stack(t_node **stack, int op);
char	*rotate_both_stacks(t_node **stack_a, t_node **stack_b);
char	*rotate_stack_reverse(t_node **stack, int operation);
char	*rotate_both_stacks_reverse(t_node **stack_a, t_node **stack_b);
bool	is_stack_sorted(t_node *stack);
bool	is_stack_reverse_sorted(t_node *stack);
bool	value_is_unique(int value, t_node *stack);
void	free_memory(t_node **stack_a, t_node **stack_b, char **args, bool dynarg);
void	error_exit(t_node **stack_a, t_node **stack_b, char **args, bool dynarg);
void	run_operation(t_node **stack_a, t_node **stack_b, int operation);
void	sort_stack(t_node **stack_a, t_node **stack_b);
void	sort_max_three(t_node **stack);
int		choose_operation(t_node **stack_a, t_node **stack_b, bool stack_a_sorted);
int		*store_stack_min_and_max(t_node *stack);
int		find_best_operation(t_node *stack_a, t_node *stack_b, int b_min_max[]);
int		*find_smaller_value_from_head(t_node *stack, int value);
int		*find_smaller_value_from_tail(t_node *stack, int value);
int		find_max_value_moves_from_head(t_node *stack, int max_value_in_stack);
int		find_max_value_moves_from_tail(t_node *stack, int max_value_in_stack);
int		*count_best_operation_for_new_min(t_node *stack_a, t_node *stack_b, int b_min_max[], int op[]);

#endif
