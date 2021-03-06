/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:06:57 by shavok            #+#    #+#             */
/*   Updated: 2022/02/15 16:56:59 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_all	*stack_create(char **argv)
{
	t_all	*all;
	char	**arr;

	arr = parsing_args(argv);
	args_validating(arr);
	all = fill_stack(arr);
	free_arr(arr, 0);
	return (all);
}

int	chech_if_sorted(t_all *all)
{
	t_node			*temp;
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	temp = all->stack_a;
	while (temp->index != 0)
	{
		temp = temp->next;
		count++;
	}
	while (i < (all->size_a) - 1)
	{
		if (temp->index > (temp->next)->index)
			return (1);
		i++;
		temp = temp->next;
	}
	if (count > (all->size_a - count))
		ops_rev_rotate(all, 0, (all->size_a) - count);
	else
		ops_rotate(all, 0, count);
	return (0);
}

int	chech_if_full_sorted(t_all *all)
{
	t_node			*temp;
	unsigned int	i;

	i = 0;
	temp = all->stack_a;
	while (i < (all->size_a) - 1)
	{
		if (temp->index > (temp->next)->index)
			return (1);
		i++;
		temp = temp->next;
	}
	return (0);
}

void	sorting(t_all *all)
{
	if (chech_if_sorted(all) == 0)
		free_stack(all);
	if (all->size_a < 6)
	{
		easy_sort(all);
		free_stack(all);
	}
	else if (all->size_a > 5)
	{
		hard_sort(all);
		free_stack(all);
	}
}

int	main(int argc, char **argv)
{
	t_all	*all;

	all = (t_all *)0;
	if (argc > 1)
	{
		all = stack_create(argv);
		sorting(all);
	}
	return (0);
}
