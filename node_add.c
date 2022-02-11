/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:32:04 by shavok            #+#    #+#             */
/*   Updated: 2022/02/11 17:33:31 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_quarter(unsigned int len, unsigned int index)
{
	unsigned int	mid;
	unsigned int	low;
	unsigned int	high;
	int				i;

	i = 0;
	mid = len / 2;
	low = mid / 2;
	high = mid + low;
	if (index < low)
		i = 1;
	else if (index >= low && index < mid)
		i = 2;
	else if (index >= mid && index < high)
		i = 3;
	else if (index >= high)
		i = 4;
	return (i);
}

t_node	*node_new(int index, int quarter)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->index = index;
	node->quarter = quarter;
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