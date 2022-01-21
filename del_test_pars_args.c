/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:24:15 by shavok            #+#    #+#             */
/*   Updated: 2022/01/16 23:27:39 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void stc_error(t_stack **stck, int i)

{
	t_stack	*nod_free;

	write (1, "Error\n", 6);
	while (i-- > 1)
	{
		nod_free = *stck;
		*stck = (*stck)->next;
		free(nod_free);
	}	
}

int	stc_check_dublicate(t_stack *stck, int num, int i)

{
	while (i-- > 0)
	{
		if (num == stck->num)
			return (-1);
		stck = stck->next;
	}
	return (0);
}

t_stack *pars_args(int argc, char **argv)

{
	int		i;
	t_stack *tmp;
	t_stack *stck_a;
	int		dub_checker;

	i = 0;
	stck_a = (t_stack *)0;
	while (++i < argc)
	{
		tmp = stack_new_nod(ft_atoi(argv[i]));
		dub_checker = stc_check_dublicate(stck_a, ft_atoi(argv[i]), i - 1);
		printf("%d\n", dub_checker);
		if (ft_atoi(argv[i]) && tmp && dub_checker >= 0)
			stack_nodadd_back(&stck_a, tmp);
		else
		{
			stc_error(&stck_a, i);
			return (NULL);
		}
	}
	return (stck_a);
}

int main(int argc, char **argv)
{
	t_stack	*stack_a;
	int	i;

	i = 0;
	stack_a = pars_args(argc, argv);
	printf("main\n");
	while (i++ < 8)
	{
		printf("%d\n", stack_a->num);
		stack_a = stack_a->next;
	}
	return (0);
}