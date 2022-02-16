/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 21:04:25 by shavok            #+#    #+#             */
/*   Updated: 2022/02/14 13:05:00 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ops_pa(t_all *all, unsigned int count)
{
	t_node	*temp;

	while (count-- > 0)
	{
		temp = all->stack_b->next;
		all->stack_b->prev->next = all->stack_b->next;
		all->stack_b->next->prev = all->stack_b->prev;
		if (all->stack_a)
		{
			all->stack_b->prev = all->stack_a->prev;
			all->stack_b->next = all->stack_a;
			all->stack_a->prev->next = all->stack_b;
			all->stack_a->prev = all->stack_b;
			all->stack_a = all->stack_b;
		}
		else
		{
			all->stack_a = all->stack_b;
			all->stack_a->next = all->stack_a;
			all->stack_a->prev = all->stack_a;
		}
		all->stack_b = temp;
		write(1, "pa\n", 3);
	}
}

void	ops_pb(t_all *all, unsigned int count)
{
	t_node	*temp;

	while (count-- > 0)
	{
		temp = all->stack_a->next;
		all->stack_a->prev->next = all->stack_a->next;
		all->stack_a->next->prev = all->stack_a->prev;
		if (all->stack_b)
		{
			all->stack_a->prev = all->stack_b->prev;
			all->stack_a->next = all->stack_b;
			all->stack_b->prev->next = all->stack_a;
			all->stack_b->prev = all->stack_a;
			all->stack_b = all->stack_a;
		}
		else
		{
			all->stack_b = all->stack_a;
			all->stack_b->next = all->stack_b;
			all->stack_b->prev = all->stack_b;
		}
		all->stack_a = temp;
		write(1, "pb\n", 3);
	}
}

void	ops_push(t_all *all, int flag, unsigned int count)
{
	if (flag == 0)
	{
		if (all->size_b == 0)
			return ;
		ops_pa(all, count);
		if (all->size_b == 1)
			all->stack_b = NULL;
		all->size_b--;
		all->size_a++;
	}
	else if (flag == 1)
	{
		if (all->size_a == 0)
			return ;
		ops_pb(all, count);
		if (all->size_a == 1)
			all->stack_a = NULL;
		all->size_a--;
		all->size_b++;
	}
}
