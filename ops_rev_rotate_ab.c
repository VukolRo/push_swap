/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rev_rotate_ab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:53:11 by shavok            #+#    #+#             */
/*   Updated: 2021/12/11 18:14:28 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ops_rev_rotate_ab(t_stack **stck_a, t_stack **stck_b)

{
	if (*stck_a && *stck_b)
	{
		*stck_a = (*stck_a)->prev;
		*stck_b = (*stck_b)->prev;
		write(1, "rrr\n", 4);
	}
	else if (!(*stck_a))
	{
		*stck_b = (*stck_b)->prev;
		write(1, "rrb\n", 4);
	}
	else if (!(*stck_b))
	{
		*stck_a = (*stck_a)->prev;
		write(1, "rra\n", 4);
	}
}