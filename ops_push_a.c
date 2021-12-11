/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:52:36 by shavok            #+#    #+#             */
/*   Updated: 2021/12/11 17:38:32 by shavok           ###   ########.fr       */
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

void	ops_push_a(t_stack **stck_a, t_stack **stck_b)

{
	t_stack *move;
	
	if (*stck_b)
	{
		if (!(*stck_a))
		{
			*stck_a = stack_new_nod((*stck_b)->num);
			stck_relink_nods(stck_b);
		}
		else if (!((*stck_b)->next == *stck_b) && !((*stck_b)->prev == *stck_b))
		{
			move = *stck_b;
			stck_relink_nods(stck_b);
			stack_nodadd_front(stck_a, move);
		}
		else if ((*stck_b)->next == *stck_b && (*stck_b)->prev == *stck_b)
		{
			move = *stck_b;
			stack_nodadd_front(stck_a, move);
			*stck_b = (t_stack *)0;
		}
		write(1, "pa\n", 3);
	}
}