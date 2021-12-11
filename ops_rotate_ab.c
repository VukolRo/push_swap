/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate_ab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:53:11 by shavok            #+#    #+#             */
/*   Updated: 2021/12/11 18:02:29 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ops_rotate_ab(t_stack **stck_a, t_stack **stck_b)

{
	if (*stck_a && *stck_b)
	{
		*stck_a = (*stck_a)->next;
		*stck_b = (*stck_b)->next;
		write(1, "rr\n", 3);
	}
	else if (!(*stck_a))
	{
		*stck_b = (*stck_b)->next;
		write(1, "rb\n", 3);
	}
	else if (!(*stck_b))
	{
		*stck_a = (*stck_a)->next;
		write(1, "ra\n", 3);
	}
}