/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:36:08 by shavok            #+#    #+#             */
/*   Updated: 2022/02/11 20:04:38 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_arr(char **arr, int flag)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
	if (flag == i)
	{
		write(2, "Error\n", 6);
		exit(EXIT_SUCCESS);
	}
}

void	free_stack(t_all *all)
{
	t_node	*temp;
	
	while (all->size_a--)
	{
		temp = all->stack_a;
		all->stack_a = all->stack_a->next;
		free(temp);
	}
	while (all->size_b--)
	{
		temp = all->stack_b;
		all->stack_b = all->stack_b->next;
		free(temp);
	}
	free(all);
	exit(0);
}

void	check_if_doublicated(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i + 1])
	{
		j = i + 1;
		while (arr[j])
		{
			if (ft_atoi_long(arr[i]) == ft_atoi_long(arr[j]))
				free_arr(arr, 1);
			j++;
		}
		i++;
	}
}

void	args_validating(char **arr)
{
	int		i;
	int		j;
	long	num;

	i = -1;
	while (arr[++i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == '-')
				j++;
			if (!(ft_isdigit(arr[i][j])))
				free_arr(arr, 1);
			j++;
		}
		num = ft_atoi_long(arr[i]);
		if (num < MIN_INT || num > MAX_INT)
			free_arr(arr, 1);
	}
	check_if_doublicated(arr);
}

char	**parsing_args(char **argv)
{
	int		i;
	char	*buff;
	char	*temp;
	char	**arr;

	buff = ft_strdup(argv[1]);
	i = 1;
	while(argv[++i])
	{
		temp = buff;
		buff = ft_strjoin(buff, " ");
		temp = buff;
		buff = ft_strjoin(buff, argv[i]);
		free(temp);
	}
	arr = ft_split(buff, ' ');
	free(buff);
	return (arr);
}