/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:52:36 by shavok            #+#    #+#             */
/*   Updated: 2021/12/10 16:56:17 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ops_push_b(t_stack **stck_a, t_stack **stck_b)

{
	t_stack	*tmp_scnd;
	t_stack *tmp_lst;
	t_stack *move;

	if (*stck_a)
	{
		tmp_scnd = (*stck_a)->next;
		tmp_lst = (*stck_a)->prev;
		if (!((*stck_a)->next == *stck_a) && !((*stck_a)->prev == *stck_a))
		{
			move = *stck_a;
			tmp_lst->next = tmp_scnd;
			tmp_scnd->prev = tmp_lst;
			*stck_a = tmp_scnd;
			stack_nodadd_front(stck_b, move);
		}
		else if ((*stck_a)->next == *stck_a && (*stck_a)->prev == *stck_a)
		{
			move = *stck_a;
			stack_nodadd_front(stck_b, move);
			*stck_a = (t_stack *)0;
		}
		write(1, "pb\n", 3);
	}
}