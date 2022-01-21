/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 21:20:42 by shavok            #+#    #+#             */
/*   Updated: 2022/01/21 21:19:57 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_full_srtd(t_stack *stck) // full sorted
{
	int i;

	i = (stck->prev)->num;
	while (stck->num != i)
	{
		if (stck->num > (stck->next)->num)
			return (1);
		stck = stck->next;
	}
	return (0);
}

int	check_if_srtd(t_stack *stck) // full sorted
{
	int i;
	int	bigest;

	i = (stck->prev)->num;
	while (stck->num != i)
	{
		if (stck->num > (stck->next)->num)
		{
			bigest = stck->num;
			while ((stck->prev)->num != bigest)
			{
				if (stck->num < (stck->prev)->num)
					return (1);
				stck = stck->prev;
			}
			return (0);
		}
		stck = stck->next;
	}
	return (0);
}

t_stack *push_swap(int ac, char **av)

{
	t_stack	*stck_a;
	
	stck_a = pars_args(ac, av);
	if (check_if_srtd(stck_a) == 0)
	{
		printf("Sorted\n");
		// !!!function CHECK_if_sorted!!!
		// 
		// if (check_if_sorted != 0)
		// {
		//	find min num and rotate or rerotate SA
		// }
		// if (check_if_full_sorted == 0)
		// {
		// 	mission completed
		// }
	}
	else
	{
		printf("Need to be sorted\n");
	// !!!function SORTING!!!
	// {
	// 	ops_push_b x 2;
	//	check if SB not sorted in reverse order ops_swap for SB;
	//	while(SA not empty)
	//	{
	//		count scr_for_each_elems in SA
	//		find and move most relevant elem to SB into sorted posision
	//	}
	//	check if SB sorted in reverse order ?????
	//	while(SB not empty)
	//	{
	//		push_a;
	//	}
	//	
	// }
	}
	return (stck_a); //push swap doesn't need to return anything but list 
						// of operations. Change function to void type.
}

int main(int argc, char **argv)
{
	t_stack	*stack_a;
	int	i;

	i = 0;
	stack_a = push_swap(argc, argv);
	while (i++ < 8)
	{
		printf("%d\n", stack_a->num);
		stack_a = stack_a->next;
	}
	return (0);
}