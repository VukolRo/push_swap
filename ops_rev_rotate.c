/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:53:11 by shavok            #+#    #+#             */
/*   Updated: 2021/12/11 18:14:34 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ops_rev_rotate(t_stack **stck, int f)
{
	if (*stck)
	{
		*stck = (*stck)->prev;
		if (f == 1)
			write(1, "rra\n", 4);
		else if (f == 2)
			write(1, "rrb\n", 4);
	}
}