/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_sort_new_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 21:04:57 by shavok            #+#    #+#             */
/*   Updated: 2022/02/08 20:56:06 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_to_sort	*to_sort_new_node(int num, unsigned int index)
{
	t_to_sort	*new_node;

	new_node = (t_to_sort *)0;
	new_node = (t_to_sort *)malloc(sizeof(t_to_sort));
	if (new_node)
	{
		new_node->num = num;
		new_node->index = index;
		new_node->next = NULL;
	}
	return (new_node);
}