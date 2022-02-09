/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap_ab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:51:39 by shavok            #+#    #+#             */
/*   Updated: 2022/02/09 00:59:50 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ops_swap_ab(t_stack **stck_a, t_stack **stck_b)

{
	int	tmp;
	t_stack *tmp_a;
	t_stack *tmp_b;

	if (*stck_a && *stck_b)
	{
		tmp_a = (*stck_a)->next;
		tmp_b = (*stck_b)->next;
		if (!(tmp_a == (*stck_a)) && !(tmp_b == (*stck_b)))
		{
			tmp = ((*stck_a)->next)->index;
			((*stck_a)->next)->index = (*stck_a)->index;
			(*stck_a)->index = tmp;
			tmp = ((*stck_b)->next)->index;
			((*stck_b)->next)->index = (*stck_b)->index;
			(*stck_b)->index = tmp;
			write(1, "ss\n", 3);
		}
		else if (!(tmp_a == (*stck_a)) && (tmp_b == (*stck_b)))
			ops_swap(stck_a, 1);
		else if ((tmp_a == (*stck_a)) && !(tmp_b == (*stck_b)))
			ops_swap(stck_b, 2);
	}
}