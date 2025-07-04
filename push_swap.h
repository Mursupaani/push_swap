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
	int				val;
	struct s_node	*next;
	struct s_node	*previous;
}	t_node;

typedef struct s_stacks
{
	t_node	*a;
	t_node	*b;
	int		a_min;
	int		a_max;
	int		a_len;
	int		b_min;
	int		b_max;
	int		b_len;
	char	**args;
	bool	dynarg;
}	t_stacks;

typedef struct s_costs
{
	int		*cur_a_ops;
	int		*cur_b_ops;
	int		*total_operations;
	int		*cur_tot_ops;
	int		best_ops[7];
	int		cur_a_pos;
	int		cur_b_pos;
	bool	first_run;
}	t_costs;

enum	e_operation_to_run_and_times_to_run
{
	OP,
	OP_TIMES,
	ROTATE,
	REVERSE_ROTATE,
	OP_SUM,
	SAME_OP,
	SAME_OP_TIMES,
	NOTHING
}	;

enum	e_best_ops
{
	A_OP,
	A_OP_TIMES,
	B_OP,
	B_OP_TIMES,
}	;

enum	e_operations
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

void	push_swap(t_stacks *stacks);
bool	pre_parse_input_args(char **args);
bool	arg_only_digits(char *arg);
bool	parse_input_args(t_stacks *stacks);
int		ft_atoi_error_exit(const char *nptr, t_stacks *stacks);
t_node	*create_new_node(int val);
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
bool	val_is_unique(int val, t_node *stack);
void	free_memory(t_stacks *stacks, t_costs *costs);
void	free_stacks_memory(t_stacks *stacks);
void	free_operation_memory(t_costs *costs);
void	free_dynamic_args(t_stacks *stacks);
void	error_exit(t_stacks *stacks, t_costs *costs);
void	run_operation_and_update_stacks(t_stacks *stacks, int operation);
void	sort_stack(t_stacks *stacks);
void	sort_max_three_in_a_stack(t_stacks *stacks);
int		choose_operation(t_stacks *stacks, bool stack_a_sorted);
void	find_best_operation_to_a(t_stacks *s);
void	find_best_operation_to_b(t_stacks *s);
void	update_stack_details(t_stacks *stacks, int operation);
int		find_val_pos(t_node *stack, int val);
int		*count_val_to_top(t_node *stack, int val, int stack_len, int *pos);
int		find_correct_val_pos_in_a(t_node *stack, int val_to_add);
int		find_correct_val_pos_in_b(t_node *stack, int val_to_add);
int		*count_correct_pos(int val, t_node *stack, int len, char op_stack);
int		*count_op_sum(int a_ops[], int b_ops[]);
void	save_best_ops(t_costs *costs);
void	run_best_ops(t_stacks *stacks, int best_ops[], char stack);
int		*store_operations_to_array(int operations[], int correct_pos, int len);
void	rotate_a_to_sort(t_stacks *stacks);

#endif
