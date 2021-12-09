/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:24:15 by shavok            #+#    #+#             */
/*   Updated: 2021/12/09 20:47:07 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *pars_args(int argc, char **argv)

{
	int		i;
	t_stack *tmp;
	t_stack *stack_a;
	
	i = 1;
	stack_a = (t_stack *)0;
	while (i < argc)
	{
		while (argv[i])
		{
			if (ft_atoi(argv[i]))
			{
				tmp = stack_new_nod(ft_atoi(argv[i]));
				stack_nodadd_back(&stack_a, tmp);
			}
			else
			{
				write (1, "Error\n", 6);
				return (NULL);
			}
			i++;
		}
	}
	return (stack_a);
}


// int main(int argc, char **argv)
// {
// 	t_stack	*stack_a;

// 	stack_a = pars_args(argc, argv);
// 	return (0);
// }