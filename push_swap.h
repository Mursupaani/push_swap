/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:25:54 by anpollan          #+#    #+#             */
/*   Updated: 2025/06/30 21:23:24 by anpollan         ###   ########.fr       */
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

typedef struct s_stacks
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		stack_a_len;
	int		stack_b_len;
	int		stack_a_min;
	int		stack_a_max;
	int		stack_b_min;
	int		stack_b_max;
	char	**args;
	bool	dynarg;
}	t_stacks;

typedef struct s_costs
{
	int		*current_a_operations;
	int		*current_b_operations;
	int		*total_operations;
	int		*current_total_operations;
	int		best_operations[7];
	bool	first_run;

	int	move_a_to_top;
	int	move_b_to_top;
	int	a_operation;
	int	b_operation;
	int	stack_a_max_pos;
	int	stack_b_max_pos;
	int	current_a_pos;
	int	current_b_pos;
}	t_costs;

enum	Operation_to_run_and_times_to_run
{
	OPERATION,
	TIMES_TO_RUN,
	ROTATE,
	REVERSE_ROTATE,
	OPERATION_SUM,
	COMMON_OPERATION,
	COMMON_OPERATION_TIMES,
	NOTHING
}	;

enum	Best_operations
{
	A_OPERATION,
	A_OPERATION_TIMES,
	B_OPERATION,
	B_OPERATION_TIMES,
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
void	print_stack(t_node *stack);
void	print_stack_reverse(t_node *stack);
void	print_detailed_stacks(t_stacks *stacks);

void	push_swap(t_stacks *stacks);
bool	pre_parse_input_args(char **args);
bool	arg_only_digits(char *arg);
bool	parse_input_args(t_stacks *stacks);
int		ft_atoi_error_exit(const char *nptr, t_stacks *stacks);
t_node	*create_new_node(int value);
t_node	*find_last_node(t_node *head);
t_node	*add_node_back(t_node **head, t_node *node_to_add);
t_node	*add_node_front(t_node **head, t_node *node_to_add);
char	*swap_top_two_elements(t_stacks *stacks, int operation);
char	*swap_tops_of_both_stacks(t_stacks *stacks);
char	*push_top_to_other_stack(t_stacks *stacks, int op);
t_node	*remove_top_element(t_node **stack);
t_node	*remove_bottom_element(t_node *stack);
char	*rotate_stack(t_stacks *stacks, int op);
char	*rotate_both_stacks(t_stacks *stacks);
char	*rotate_stack_reverse(t_stacks *stacks, int operation);
char	*rotate_both_stacks_reverse(t_stacks *stacks);
bool	is_stack_sorted(t_node *stack);
bool	is_stack_reverse_sorted(t_node *stack);
bool	value_is_unique(int value, t_node *stack);
void	free_memory(t_stacks *stacks, t_costs *costs);
void	free_stacks_memory(t_stacks *stacks);
void	free_operation_memory(t_costs *costs);
void	free_dynamic_args(t_stacks *stacks);
void	error_exit(t_stacks *stacks, t_costs *costs);
void	run_operation_and_update_stacks(t_stacks *stacks, int operation);
void	sort_stack(t_stacks *stacks);
void	sort_max_three_in_a_stack(t_stacks *stacks);
int		choose_operation(t_stacks *stacks, bool stack_a_sorted);
int		*store_stack_min_and_max(t_node *stack);
void	find_best_operation_to_a(t_stacks *stacks);
void	find_best_operation_to_b(t_stacks *stacks);
void	update_stack_details(t_stacks *stacks, int operation);
int		find_value_pos(t_node *stack, int value);
int		*calculate_value_to_top(t_node *stack, int max_value, int stack_len, int *pos);
int		find_correct_value_pos_in_a(t_node *stack, int value_to_add);
int		find_correct_value_pos_in_b(t_node *stack, int value_to_add);
int		*calculate_correct_position(int value_to_add, t_node *stack_to_append, int stack_len, char stack);
int		*calculate_operation_sum(int a_operations[], int b_operations[]);
void	save_best_operations(t_costs *costs);
void	run_best_operations(t_stacks *stacks, int best_operations[], char stack);
void	find_best_push_or_rot_a(t_stacks *stacks);
int		*store_operations_to_array(int operations[], int correct_position, int stack_len);

#endif
