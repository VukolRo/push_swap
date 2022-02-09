/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 22:01:41 by shavok            #+#    #+#             */
/*   Updated: 2022/02/09 00:13:22 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	args_count(char **args)
{
	int		i;
	int		args_count;

	i = 0;
	args_count = 0;

	while (args[i++])
		args_count++;
	return (args_count);
}

int check_is_digit(char *to_check)
{
	int	i;

	i = 0;
	while (to_check[i])
	{
		if (to_check[i] == '+' || to_check[i] == '-' )
				i++;
		if (to_check[i] > '9' || to_check[i] < '0')
			return (1);
		i++;
	}
	return (0);
}

int check_error(char *to_pars, int *unsorted, int len)

{
	int	min;
	int	max;
	long	value;
	int		i;

	i = 0;
	max = 2147483647;
	min = -2147483648;
	if (check_is_digit(to_pars) == 1)
		return (1);
	value = ft_atoi_long(to_pars);
	if (value > max || value < min)
		return (1);
	while (i < len)
	{
		if (unsorted[i] == value)
			return(1);
		i++;
	}
	return (0);
}

int *pars_to_unsorted(int *unsorted, int ac, char **av)
{
	int i;

	i = 0;
	unsorted = ft_calloc((ac), sizeof (int));
	if (unsorted)
	{
		while (i < ac)
		{
			if (check_error(av[i], unsorted, i) == 0)
			{
				unsorted[i] = ft_atoi_long(av[i]);
			}
			else if (check_error(av[i], unsorted, i) == 1)
			{
				free(unsorted);
				write(1, "Error\n", 6);
				break;
			}
			i++;
		}
	}
	return (unsorted);
}

int	*args_validation(int argc, char **argv)
{
	int	*unsorted;

	unsorted = (int *)0;
	if (argc == 2)
	{
		if (ft_strchr(argv[1], ' '))
		{
			char	**args;
			args = ft_split(argv[1], ' ');
			unsorted = pars_to_unsorted(unsorted, (args_count(args)), args);
		}
	}
	else if (argc > 2)
		unsorted = pars_to_unsorted(unsorted, (argc - 1), (argv + 1));
	return (unsorted);
}