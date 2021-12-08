/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_nodadd_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 22:18:37 by shavok            #+#    #+#             */
/*   Updated: 2021/12/08 23:03:17 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_nodadd_back(t_stack **lst, t_stack *new)

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
	}
}