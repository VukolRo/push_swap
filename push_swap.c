/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 21:20:42 by shavok            #+#    #+#             */
/*   Updated: 2021/12/11 21:51:10 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_srtd(t_stack *stck, int count)
{
	int i;

	i = 1;
	while (i++ < count)
	{
		if (stck->num > (stck->next)->num)
			return (1);
		else
			stck = stck->next;
	}
	return (0);
}

t_stack *push_swap(int ac, char **av)
{
	t_stack	*stck_a;
	int	i;
	int count;

	i = 0;
	count = ac - 1;
	stck_a = pars_args(ac, av);
	if (check_if_srtd(stck_a, count) == 0)
		printf("Sorted\n");
	else
		printf("Need to be sorted\n");
	// if (stack_a)
	// {
		
	// }
	return (stck_a);
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