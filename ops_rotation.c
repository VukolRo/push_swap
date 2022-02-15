/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 19:39:00 by shavok            #+#    #+#             */
/*   Updated: 2022/02/15 14:13:49 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ops_rev_rotate(t_all *all, int flag, unsigned int count)
{
	while (count-- > 0)
	{
		if (flag == 0 && all->size_a > 1)
		{
			all->stack_a = all->stack_a->prev;
			write(1, "rra\n", 4);
		}
		else if (flag == 1 && all->size_b > 1)
		{
			all->stack_b = all->stack_b->prev;
			write(1, "rrb\n", 4);
		}
	}
}

void	ops_rev_rotate_ab(t_all *all, unsigned int count)
{
	while (count-- > 0)
	{
		if (all->size_a > 1 && all->size_b > 1)
		{
			all->stack_a = all->stack_a->prev;
			all->stack_b = all->stack_b->prev;
			write(1, "rrr\n", 4);
		}
		else if (all->size_b > 1 && all->size_a < 2)
		{
			all->stack_b = all->stack_b->prev;
			write(1, "rrb\n", 4);
		}
		else if (all->size_a > 1 && all->size_b < 2)
		{
			all->stack_a = all->stack_a->prev;
			write(1, "rra\n", 4);
		}
	}
}

void	ops_rotate(t_all *all, int flag, unsigned int count)
{
	while (count-- > 0)
	{
		if (flag == 0 && all->size_a > 1)
		{
			all->stack_a = all->stack_a->next;
			write(1, "ra\n", 3);
		}
		else if (flag == 1 && all->size_b > 1)
		{
			all->stack_b = all->stack_b->next;
			write(1, "rb\n", 3);
		}
	}
}

void	ops_rotate_ab(t_all *all, unsigned int count)
{
	while (count-- > 0)
	{
		if (all->size_a > 1 && all->size_b > 1)
		{
			all->stack_a = all->stack_a->next;
			all->stack_b = all->stack_b->next;
			write(1, "rr\n", 3);
		}
		else if (all->size_b > 1 && all->size_a < 2)
		{
			all->stack_b = all->stack_b->next;
			write(1, "rb\n", 3);
		}
		else if (all->size_a > 1 && all->size_b < 2)
		{
			all->stack_a = all->stack_a->next;
			write(1, "ra\n", 3);
		}
	}
}