/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:24:15 by shavok            #+#    #+#             */
/*   Updated: 2021/12/08 21:24:54 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void *pars_args(int argc, char **argv, int *nums)

{
	int		i;
	
	i = 1;
	while (i < argc)
	{
		while (argv[i])
		{
			if (!(nums[i - 1] = ft_atoi(argv[i])))
			{
				write (1, "Error\n", 6);
				return (NULL);
			}
			i++;
		}
	}
	return (nums);
}


int main(int argc, char **argv)
{
	int 	*nums;
	int		i;
	// t_stack	stack_a;
	
	nums = ft_calloc((argc), sizeof(int));
	if (nums)
	{
		pars_args(argc, argv, nums);
		i = 0;
		while (nums[i])
		{
			printf("%d\n", nums[i]);
			i++;
		}
	}
	return (0);
}