/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:08:28 by shavok            #+#    #+#             */
/*   Updated: 2022/02/14 14:32:24 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shorter_way(t_all *all)
{
	t_node	*temp;

	temp = all->stack_b;
	all->rr_to_next = 0;
	all->r_to_next = 0;
	while (temp->index != all->max_sorted)
	{
		all->r_to_next += 1;
		temp = temp->next;
	}
	temp = all->stack_b;
	while (temp->index != all->max_sorted)
	{
		all->rr_to_next += 1;
		temp = temp->prev;
	}
}

void	insertion_sort(t_all *all)
{
	while (all->size_b > 0)
	{
		shorter_way(all);
		if (all->rr_to_next < all->r_to_next)
			ops_rev_rotate(all, 1, all->rr_to_next);
		else if (all->r_to_next <= all->rr_to_next)
			ops_rotate(all, 1, all->r_to_next);
		ops_push(all, 0, 1);
		ops_rotate(all, 0, 1);
		all->max_sorted += 1;
	}
}