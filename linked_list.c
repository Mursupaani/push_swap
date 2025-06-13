/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:16:14 by anpollan          #+#    #+#             */
/*   Updated: 2025/06/13 16:15:55 by anpollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_new_node(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	new_node->previous = NULL;
	return (new_node);
}

t_node	*find_last_node(t_node *head)
{
	t_node	*last_node;

	if (!head)
		return (NULL);
	last_node = head;
	while (last_node)
	{
		if (last_node->next == NULL)
			return (last_node);
		last_node = last_node->next;
	}
	return (last_node);
}

t_node	*add_node_back(t_node **head, t_node *node_to_add)
{
	t_node	*last_node;

	if (!head)
		return (NULL);
	last_node = find_last_node(*head);
	if (!last_node)
	{
		*head = node_to_add;
		return (*head);
	}
	else
	{
		last_node->next = node_to_add;
		node_to_add->previous = last_node;
		return (node_to_add);
	}
}

t_node	*add_node_front(t_node **head, t_node *node_to_add)
{
	if (!head)
		return (NULL);
	if (!*head)
	{
		*head = node_to_add;
		return (*head);
	}
	else
	{
		(*head)->previous = node_to_add;
		node_to_add->next = *head;
		return (node_to_add);
	}
}
