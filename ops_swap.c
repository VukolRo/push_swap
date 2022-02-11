/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 21:33:14 by shavok            #+#    #+#             */
/*   Updated: 2022/02/11 21:41:45 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ops_swap_a(t_all *all)
{
	unsigned int	temp;
	
	if (all->size_a > 1)
	{
		temp = all->stack_a->index;
		all->stack_a->index = all->stack_a->next->index;
		all->stack_a->next->index = temp;
		write(1, "sa\n", 3);
	}
}

void ops_swap_b(t_all *all)
{
	unsigned int	temp;

	if (all->size_b > 1)
	{
		temp = all->stack_b->index;
		all->stack_b->index = all->stack_b->next->index;
		all->stack_b->next->index = temp;
		write(1, "sb\n", 3);
	}
}

void ops_swap_ab(t_all *all)
{
	unsigned int	temp;

	if (all->size_a > 1 && all->size_b > 1)
	{
		temp = all->stack_a->index;
		all->stack_a->index = all->stack_a->next->index;
		all->stack_a->next->index = temp;
		temp = all->stack_b->index;
		all->stack_b->index = all->stack_b->next->index;
		all->stack_b->next->index = temp;
		write(1, "ss\n", 3);
	}
	else if (all->size_a > 1 && all->size_b < 2)
		ops_swap_a(all);
	else if (all->size_b > 1 && all->size_a < 2)
		ops_swap_b(all);
}