/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_new_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:56:52 by shavok            #+#    #+#             */
/*   Updated: 2022/02/09 00:03:49 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new_node(unsigned int index, unsigned int quarter)

{
	t_stack	*e1;

	e1 = (t_stack *)0;
	e1 = (t_stack *)malloc(sizeof(t_stack));
	if (e1)
	{
		e1->index = index;
		e1->quarter = quarter;
		e1->next = e1;
		e1->prev = e1;
	}
	return (e1);
}