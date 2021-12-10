/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:52:36 by shavok            #+#    #+#             */
/*   Updated: 2021/12/10 17:19:27 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ops_push_a(t_stack **stck_a, t_stack **stck_b)

{
	t_stack	*tmp_scnd;
	t_stack *tmp_lst;
	t_stack *move;
	
	if (*stck_b)
	{
		tmp_scnd = (*stck_b)->next;
		tmp_lst = (*stck_b)->prev;
		if (!(*stck_a))
		{
			*stck_a = stack_new_nod((*stck_b)->num);
			tmp_lst->next = tmp_scnd;
			tmp_scnd->prev = tmp_lst;
			*stck_b = tmp_scnd;
		}
		else if (!((*stck_b)->next == *stck_b) && !((*stck_b)->prev == *stck_b))
		{
			move = *stck_b;
			tmp_lst->next = tmp_scnd;
			tmp_scnd->prev = tmp_lst;
			*stck_b = tmp_scnd;
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