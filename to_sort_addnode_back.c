/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_sort_addnode_back.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 21:15:45 by shavok            #+#    #+#             */
/*   Updated: 2022/02/08 20:56:12 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_to_sort	*to_sort_addnode_back(t_to_sort *to_sort, t_to_sort *new)

{
	t_to_sort *tmp;

	tmp = (t_to_sort *)0; 
	if (new)
	{

		if (to_sort == NULL)
		{
			to_sort = new;
		}
		else
		{
			tmp = to_sort;
			while (tmp->next)
			{
				tmp = tmp->next;
			}
			tmp->next = new;
		}
	}
	return (to_sort);
}