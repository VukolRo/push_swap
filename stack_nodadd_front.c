/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_nodadd_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:59:48 by shavok            #+#    #+#             */
/*   Updated: 2021/12/10 15:22:30 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_nodadd_front(t_stack **stck, t_stack *new)

{
	t_stack *tmp_fst;
	t_stack *tmp_lst;

	if (*stck && new)
	{
		tmp_fst = *stck;
		tmp_lst = (*stck)->prev;

		new->next = tmp_fst;
		new->prev = tmp_lst;
		tmp_fst->prev = new;
		tmp_lst->next = new;
		*stck = new;
	}
}