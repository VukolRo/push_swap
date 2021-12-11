/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:52:36 by shavok            #+#    #+#             */
/*   Updated: 2021/12/11 17:38:14 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stck_relink_nods(t_stack **stck)
{
	t_stack	*tmp_scnd;
	t_stack *tmp_lst;

	tmp_scnd = (*stck)->next;
	tmp_lst = (*stck)->prev;
	tmp_lst->next = tmp_scnd;
	tmp_scnd->prev = tmp_lst;
	*stck = tmp_scnd;
}


void	ops_push_b(t_stack **stck_a, t_stack **stck_b)

{
	t_stack *move;
	
	if (*stck_a)
	{
		if (!(*stck_b))
		{
			*stck_b = stack_new_nod((*stck_a)->num);
			stck_relink_nods(stck_a);
		}
		else if (!((*stck_a)->next == *stck_a) && !((*stck_a)->prev == *stck_a))
		{
			move = *stck_a;
			stck_relink_nods(stck_a);
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