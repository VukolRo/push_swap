/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 21:00:24 by shavok            #+#    #+#             */
/*   Updated: 2022/02/15 21:18:31 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_down(t_all *all)
{
	all->stack_a->flag = -1;
	ops_rotate(all, 0, 1);
}

void	sort_for_three(t_all *all)
{
	if ((all->stack_a)->index == 2 && ((all->stack_a)->next)->index == 1)
	{
		ops_swap_a(all);
		ops_rev_rotate(all, 0, 1);
	}
	else if (all->stack_a->index == 0 && all->stack_a->next->index == 2)
	{
		ops_swap_a(all);
		ops_rotate(all, 0, 1);
	}
	else if (all->stack_a->index == 1 && all->stack_a->next->index == 0)
		ops_swap_a(all);
	else if (all->stack_a->index == 1 && all->stack_a->next->index == 2)
		ops_rev_rotate(all, 0, 1);
	else if (all->stack_a->index == 2 && all->stack_a->next->index == 0)
		ops_rotate(all, 0, 1);
}

void	easy_sort(t_all *all)
{
	while (all->size_a > 3)
	{
		if (all->stack_a->index > 2)
			ops_push(all, 1, 1);
		else
			ops_rotate(all, 0, 1);
	}
	sort_for_three(all);
	if (all->size_b == 2)
	{
		if (all->stack_b->index == 4)
			ops_swap_b(all);
		ops_push(all, 0, 1);
		ops_rotate(all, 0, 1);
		ops_push(all, 0, 1);
		ops_rotate(all, 0, 1);
	}
	else if (all->size_b == 1)
		ops_push(all, 0, 1);
}