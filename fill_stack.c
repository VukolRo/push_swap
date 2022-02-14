/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:34:22 by shavok            #+#    #+#             */
/*   Updated: 2022/02/14 13:51:29 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_struct(t_all *all, char **arr)
{
	unsigned int	i;

	i = 0;
	while (arr[i])
		i++;
	if (all == NULL)
		return ;
	all->stack_a = NULL;
	all->stack_b = NULL;
	all->size_a = i;
	all->size_b = 0;
	all->max_sorted = 0;
}

void	bubble_sorting(int *sorted, unsigned int len)
{
	unsigned int	i;
	unsigned int	j;
	int	temp;


	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < (len - 1 - i))
		{
			if (sorted[j] > sorted[j + 1])
			{
				temp = sorted[j];
				sorted[j] = sorted[j + 1];
				sorted[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	fill_index(t_all *all, int *unsorted, int *sorted)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < (all->size_a))
	{
		j = 0;
		while (j < (all->size_a))
		{
			if (unsorted[i] == sorted[j])
			{
				node_add_back(&all->stack_a, node_new(j, find_quarter(j, (all->size_a))));
				j++;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	find_index(t_all *all, char **arr)
{
	int	*unsorted;
	int	*sorted;
	unsigned int	i;

	i = 0;
	unsorted = malloc(sizeof(int) * (all->size_a));
	sorted = malloc(sizeof(int) * (all->size_a));
	if (unsorted && sorted)
	{
		while (i < (all->size_a))
		{
			unsorted[i] = (int)ft_atoi_long(arr[i]);
			sorted[i] = (int)ft_atoi_long(arr[i]);
			i++;
		}
		bubble_sorting(sorted, (all->size_a));
		fill_index(all, unsorted, sorted);
		free(unsorted);
		free(sorted);
	}
}

t_all	*fill_stack(char **arr)
{
	t_all			*all;

	all = malloc(sizeof(t_all));
	create_struct(all, arr);
	find_index(all, arr);
	return(all);
}