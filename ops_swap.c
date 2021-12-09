/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:51:39 by shavok            #+#    #+#             */
/*   Updated: 2021/12/09 21:56:48 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ops_swap(t_stack **stck, int f)

{
	int	tmp;
	t_stack *tmp1;

	if (*stck)
	{
		tmp1 = (*stck)->next;
		if (!(tmp1 == (*stck)))
		{
			tmp = ((*stck)->next)->num;
			((*stck)->next)->num = (*stck)->num;
			(*stck)->num = tmp;
			if (f == 1)
				write(1, "sa\n", 3);
			else if (f == 2)
				write(1, "sb\n", 3);
		}
	}
}