/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_five_between.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:17:51 by shavok            #+#    #+#             */
/*   Updated: 2022/02/15 21:01:09 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_b_to_a(t_all *all)
{
	int	first;
	int	second;
	int	last;

	if (all->size_b == 0)
		return ;
	first = all->stack_b->index;
	second = all->stack_b->next->index;
	last = all->stack_b->prev->index;
	if (second > first && second > last)
		ops_rev_rotate(all, 1, 1);
	else if (first > second && first > last)
		ops_rotate(all, 1, 1);
	first = all->stack_b->index;
	second = all->stack_b->next->index;
	if (first > second)
		ops_swap_b(all);
}

void	three_a_to_b(t_all *all, int flag)
{
	sort_three_b_to_a(all);
	if (all->stack_a->index > all->stack_a->next->index && \
		all->stack_a->flag == all->stack_a->next->flag)
		ops_swap_a(all);
	while (all->size_b != 0)
	{
		if (all->stack_a->index > all->stack_b->index || \
			all->stack_a->flag != flag)
		{
			ops_push(all, 0, 1);
			push_down(all);
		}
		else
			push_down(all);
	}
	while (all->stack_a->flag == flag && flag != -1)
		push_down(all);
}

void	three_b_to_a(t_all *all, int flag)
{
	sort_three_b_to_a(all);
	if (all->stack_a->index > all->stack_a->next->index && \
		all->stack_a->flag == all->stack_a->next->flag)
		ops_swap_a(all);
	while (all->size_b != 0)
	{
		if (all->stack_a->index > all->stack_b->index || \
			all->stack_a->flag == -1)
		{
			ops_push(all, 0, 1);
			push_down(all);
		}
		else
			push_down(all);
	}
	while (all->stack_a->flag == flag && flag != -1 && \
			all->stack_a->index + 1 == all->stack_a->prev->index)
		push_down(all);
}

void	five_a_to_b(t_all *all, int flag, unsigned int min, int i)
{
	t_node	*tmp;

	min = all->stack_a->prev->index + 1;
	flag = all->stack_a->flag;
	tmp = all->stack_a;
	while (tmp->flag == flag && flag != -1)
	{
		tmp = tmp->next;
		i++;
	}
	if (i <= 5)
	{
		while (i > 2)
		{
			if (all->stack_a->index == min)
			{
				push_down(all);
				min++;
			}
			else
				ops_push(all, 1, 1);
			i--;
		}
		three_a_to_b(all, flag);
	}
}

void	five_b_to_a(t_all *all)
{
	int				flag;
	unsigned int	min;
	unsigned int	i;

	i = all->size_b;
	min = all->stack_a->prev->index + 1;
	flag = all->stack_a->flag;
	while (i > 3)
	{
		if (all->stack_b->index == min)
		{
			ops_push(all, 0, 1);
			push_down(all);
			min++;
		}
		else
			ops_push(all, 0, 1);
		i--;
	}
	three_b_to_a(all, flag);
}