/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_for_hard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 21:13:59 by shavok            #+#    #+#             */
/*   Updated: 2022/02/15 21:15:42 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_min_a_to_b(t_all *all)
{
	unsigned int	min;

	min = all->stack_a->prev->index + 1;
	if (all->stack_b->index == min)
	{
		ops_push(all, 0, 1);
		push_down(all);
	}
	else if (all->stack_b->next->index == min)
	{
		ops_swap_b(all);
		ops_push(all, 0, 1);
		push_down(all);
	}
	else if (all->stack_b->prev->index == min)
	{
		ops_rev_rotate(all, 1, 1);
		ops_push(all, 0, 1);
		push_down(all);
	}
	else if (all->stack_a->next->index == min)
	{
		ops_swap_a(all);
		push_down(all);
	}
}

int	find_next_sorted(t_all *all)
{
	unsigned int	min;

	min = all->stack_a->prev->index + 1;
	if (all->stack_b->index == min)
	{
		ops_push(all, 0, 1);
		push_down(all);
		return (0);
	}
	else if (all->stack_a->index == min)
		push_down(all);
	else if (all->stack_a->next->index == min)
	{
		ops_swap_a(all);
		push_down(all);
	}
	return (1);
}

void	find_mmm_a(t_all *all)
{
	unsigned int	i;

	if (all->size_a == 0)
		return ;
	all->min = all->stack_a->index;
	all->max = all->min;
	i = all->size_a;
	while (i-- > 0)
	{
		if (all->min > all->stack_a->index && all->stack_a->flag != -1)
			all->min = all->stack_a->index;
		if (all->max < all->stack_a->index && all->stack_a->flag != -1)
			all->max = all->stack_a->index;
		all->stack_a = all->stack_a->next;
	}
	all->median = (all->max + all->min) / 2;
}

void	find_mmm_b(t_all *all)
{
	unsigned int	i;

	if (all->size_b == 0)
		return ;
	all->min = all->stack_b->index;
	all->max = all->min;
	i = all->size_b;
	while (i-- > 0)
	{
		if (all->min > all->stack_b->index)
			all->min = all->stack_b->index;
		if (all->max < all->stack_b->index)
			all->max = all->stack_b->index;
		all->stack_b = all->stack_b->next;
	}
	all->median = (all->max + all->min) / 2;
}
