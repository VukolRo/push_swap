/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:12:46 by shavok            #+#    #+#             */
/*   Updated: 2022/02/16 20:01:37 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorted_to_a(t_all *all)
{
	while (all->stack_b->prev->flag == -1)
		ops_rev_rotate(all, 1, 1);
	while (all->stack_b->flag == -1)
	{
		ops_push(all, 0, 1);
		ops_rotate(all, 0, 1);
	}
}

void	first_to_b(t_all *all)
{
	int	i;

	find_mmm_a(all);
	i = all->size_a;
	while (i-- > 0 && all->stack_a->flag != -1)
	{
		if (all->stack_a->index <= all->median
			&& all->stack_a->index >= all->min)
		{
			ops_push(all, 1, 1);
			if (all->stack_b->index == all->min)
			{
				all->stack_b->flag = -1;
				all->min += 1;
				ops_rotate(all, 1, 1);
			}
		}
		else
		{
			if (all->size_b == all->max - all->median + 1)
				break ;
			ops_rotate(all, 0, 1);
		}
	}
	sorted_to_a(all);
}

void	all_to_a(t_all *all)
{
	unsigned int	i;

	find_mmm_b(all);
	i = all->size_b;
	while (i-- > 0)
	{
		if (find_next_sorted(all) == 0)
			continue ;
		if (all->stack_b->index > all->median)
		{
			all->stack_b->flag++;
			ops_push(all, 0, 1);
		}
		else
		{
			all->stack_b->flag++;
			ops_rotate(all, 1, 1);
		}
	}
}

void	next_to_b(t_all *all)
{
	int				flag;
	unsigned int	min;

	flag = all->stack_a->flag;
	while (all->stack_a->flag == flag && flag != -1)
	{
		min = all->stack_a->prev->index + 1;
		if (all->size_b > 1)
			find_min_a_to_b(all);
		if (all->stack_a->index == min)
			push_down(all);
		else
			ops_push(all, 1, 1);
	}
}

void	hard_sort(t_all *all)
{
	first_to_b(all);
	while (!(chech_if_full_sorted(all) == 0 && all->size_b == 0))
	{
		if (all->size_b > 0 && all->size_b < 6)
		{
			five_b_to_a(all);
		}
		else if (all->size_b > 5)
		{
			all_to_a(all);
		}
		if (all->size_b == 0)
		{
			five_a_to_b(all, 0, 0, 0);
			next_to_b(all);
		}
	}
}
