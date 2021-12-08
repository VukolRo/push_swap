/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_nodadd_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:59:48 by shavok            #+#    #+#             */
/*   Updated: 2021/12/08 23:02:45 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_nodadd_front(t_stack **lst, t_stack *new)

{
	t_stack *tmp_f;
	t_stack *tmp_l;

	if (*lst && new)
	{
		tmp_f = *lst;
		tmp_l = tmp_f->prev;

		new->next = tmp_f;
		new->prev = tmp_l;
		tmp_f->prev = new;
		tmp_l->next = new;
		*lst = new;
	}
}