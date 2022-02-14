/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:12:46 by shavok            #+#    #+#             */
/*   Updated: 2022/02/14 14:42:38 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_mid_quarters(t_all *all)
{
	unsigned int	i;

	i = all->size_a;
	while (i-- > 0)
	{
		if (all->stack_a->quarter == 3)
		{
			ops_push(all, 1, 1);
			ops_rotate(all, 1, 1);
		}
		else if (all->stack_a->quarter == 2)
			ops_push(all, 1, 1);
	}
}

void	push_head_n_tail_quarters(t_all *all)
{
	unsigned int	i;

	i = all->size_a;
	while (i-- > 0)
	{
		if (all->stack_a->quarter == 4)
		{
			ops_push(all, 1, 1);
			ops_rotate(all, 1, 1);
		}
		else if (all->stack_a->quarter == 1)
			ops_push(all, 1, 1);
	}
}

void	hard_sort(t_all *all)
{
	push_mid_quarters(all);
	push_head_n_tail_quarters(all);
	insertion_sort(all);
}