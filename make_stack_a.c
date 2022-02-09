/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 22:09:04 by shavok            #+#    #+#             */
/*   Updated: 2022/02/09 00:07:19 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	find_quarter(unsigned int index, unsigned int len)
{
	unsigned int	first;
	unsigned int	mid;
	unsigned int	third;
	unsigned int	quarter;

	mid = len / 2;
	first = mid / 2;
	third = len - first;
	if (index <= first)
		quarter = 1;
	else if (index > first && index <= mid)
		quarter = 2;
	else if (index > mid && index <= third)
		quarter = 3;
	else if (index > third)
		quarter = 4;
	return(quarter);

}

t_to_sort	*find_index(t_to_sort *unsorted, t_to_sort *sorted, unsigned int len)

{
	unsigned int	i;
	unsigned int	j;
	t_to_sort		*temp_s;
	t_to_sort		*temp_uns;

	i = 0;
	temp_s = sorted;
	temp_uns = unsorted;
	while (i < len)
	{
		j = 0;
		while (unsorted->num != sorted->num)
		{
			sorted = sorted->next;
			j++;
		}
		unsorted->index = j;
		unsorted = unsorted->next;
		sorted = temp_s;
		i++;
	}
	unsorted = temp_uns;
	return (unsorted);
}

t_stack	**make_stack_a(t_to_sort *unsorted, t_to_sort *sorted, unsigned int len)

{
	t_stack	**stack_a;
	t_stack	*new;
	unsigned int	i;

	i = 0;
	stack_a = (t_stack **)malloc(sizeof(t_stack *) * len);
	find_index(unsorted, sorted, len);
	while (i++ < len)
	{
		new = stack_new_node(unsorted->index, find_quarter(unsorted->index, len));
		stack_nodeadd_back(stack_a, new);
		unsorted = unsorted->next;
	}
	return (stack_a);
}