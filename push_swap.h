/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:25:54 by anpollan          #+#    #+#             */
/*   Updated: 2025/06/13 20:44:38 by anpollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*previous;
}	t_node;

t_node	*create_new_node(int value);
t_node	*find_last_node(t_node *head);
t_node	*add_node_back(t_node **head, t_node *node_to_add);
t_node	*add_node_front(t_node **head, t_node *node_to_add);
void	print_stack(t_node *stack);
void	swap_top_two_elements(t_node **stack);
void	push_top_to_other_stack(t_node **from_stack, t_node **to_stack);
t_node	*remove_top_element(t_node **stack);
t_node	*remove_bottom_element(t_node *stack);
void	print_reverse_stack(t_node *stack);

#endif
