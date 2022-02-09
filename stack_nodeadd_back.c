/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_nodeadd_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 22:18:37 by shavok            #+#    #+#             */
/*   Updated: 2022/02/08 22:54:32 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_nodeadd_back(t_stack **stck, t_stack *new)

{
	t_stack *tmp_fst;
	t_stack *tmp_lst;

	if (new)
	{
		if (!(*stck))
		{
			*stck = new;
		}
		else
		{
			tmp_fst = *stck;
			tmp_lst = (*stck)->prev;
			new->next = tmp_fst;
			tmp_lst->next = new;
			new->prev = tmp_lst;
			(*stck)->prev = new;
		}
	}
}