/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bubble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:37:07 by shavok            #+#    #+#             */
/*   Updated: 2022/02/08 20:39:58 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arr_is_sorted(t_to_sort *to_check)
{
	t_to_sort	*temp;

	temp = to_check;
	while (temp->next)
	{
		if (temp->num > (temp->next)->num)
			return(1);
		temp = temp->next;
	}
	return (0);
}

t_to_sort	*sort_bubble(t_to_sort *to_sort)
{
	int tmp;
	t_to_sort	*temp;

	tmp = 0;
	temp = to_sort;
	while (arr_is_sorted(temp) != 0)
	{
		while (to_sort->next != NULL)
		{
			if (to_sort->num > (to_sort->next)->num)
			{
				tmp = to_sort->num;
				to_sort->num = (to_sort->next)->num;
				(to_sort->next)->num = tmp;
			}
			to_sort = to_sort->next;
		}
		to_sort = temp;
	}
	return (to_sort);
}