/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:15:38 by anpollan          #+#    #+#             */
/*   Updated: 2025/06/13 19:42:30 by anpollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_node *head)
{
	if (head)
	{
		while (head)
		{
			ft_printf("%d", head->value);
			if (head->next)
				ft_printf(" ");
			else
				ft_printf("\n");
			head = head->next;
		}
	}
}
