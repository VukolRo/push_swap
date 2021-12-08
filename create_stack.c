/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 21:14:57 by shavok            #+#    #+#             */
/*   Updated: 2021/12/08 21:26:15 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	int 	*nums;
	int		i;
	t_stack	*stack_a;
	
	i = 0;
	nums = ft_calloc((argc), sizeof(int));
	if (nums)
	{
		pars_args(argc, argv, nums);
		stack_a = (t_stack *)malloc(sizeof(t_stack));
		while (i < argc)
		{
			stack_new_nod(nums[i]);
			
		}
	}
	return (0);
}