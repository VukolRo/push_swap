/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:32:04 by shavok            #+#    #+#             */
/*   Updated: 2022/02/15 18:00:32 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*node_new(int index)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->index = index;
	node->flag = 0;
	node->next = node;
	node->prev = node;
	return(node);
}

void	node_add_back(t_node **stack, t_node *new)
{
	t_node	*temp;

	if (new)
	{
		temp = *stack;
		if (temp)
		{
			if (temp->next != temp && temp->prev != temp)
			{
				(temp->prev)->next = new;
				new->prev = temp->prev;
				new->next = temp;
				temp->prev = new;
			}
			else
			{
				temp->next = new;
				temp->prev = new;
				new->next = temp;
				new->prev = temp;
			}
		}
		else
			*stack = new;
	}
}