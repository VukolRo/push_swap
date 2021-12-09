/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_new_nod.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:56:52 by shavok            #+#    #+#             */
/*   Updated: 2021/12/09 20:37:16 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new_nod(int numbr)

{
	t_stack	*e1;

	e1 = (t_stack *)0;
	e1 = (t_stack *)malloc(sizeof(t_stack));
	if (e1)
	{
		e1->num = numbr;
		e1->next = e1;
		e1->prev = e1;
		// printf("%d ", e1->num);
	}
	return (e1);
}