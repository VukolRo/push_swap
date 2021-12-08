/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_new_nod.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:56:52 by shavok            #+#    #+#             */
/*   Updated: 2021/12/08 21:20:59 by shavok           ###   ########.fr       */
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
		e1->next = (t_stack *)0;
		e1->previous = (t_stack *)0;
	}
	return (e1);
}