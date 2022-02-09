/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:01:25 by shavok            #+#    #+#             */
/*   Updated: 2022/02/09 00:14:11 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_to_sort	*write_to_sort(int *unsodrted, unsigned int len)

{
	unsigned int	i;
	t_to_sort		*new;
	t_to_sort		*to_sort;

	i = 0;
	to_sort = (t_to_sort *)0;
	while(i < len)
	{
		new = to_sort_new_node(unsodrted[i], 0);
		to_sort = to_sort_addnode_back(to_sort, new);
		i++;
	}
	return(to_sort);
}

unsigned int	len_by_argc(int argc, char **argv)
{
	unsigned int	len;
	
	len = 0;
	if (argc == 2)
	{
		if (ft_strchr(argv[1], ' '))
		{
			char	**args;

			args = ft_split(argv[1], ' ');
			len = args_count(args);
		}
	}
	else if (argc > 2)
		len = argc - 1;
	return(len);
}

t_to_sort *convert_parsed_to_sort(int *unsorted, int argc, char **argv)

{
	t_to_sort		*to_sort;
	unsigned int	len;
	
	len = len_by_argc(argc, argv);
	to_sort = write_to_sort(unsorted, len);
	return(to_sort);
}


t_stack **parsing_args(int argc, char **argv)

{
	// 1. Check that data(argv) is valid, if not show Error, and close program,
	// 		if data is valid pars it to array of ints
	// 2. Sort(by bubble algo) array of finde an indexes for each node
	// 3. Returtn t_stack stck_a, with indexes
	
	int				*unsorted;
	t_to_sort		*to_sort;
	t_to_sort		*sorted;
	t_stack			**stack_a;
	unsigned int	i;

	i = 0;
	stack_a = (t_stack **)0;
	// 1
	unsorted = args_validation(argc, argv);
	to_sort = convert_parsed_to_sort(unsorted, argc, argv);
	// 2
	sorted = sort_bubble(convert_parsed_to_sort(unsorted, argc, argv));
	// 3
	stack_a = make_stack_a(to_sort, sorted, len_by_argc(argc, argv));
	return (stack_a);
}

// int main(int argc, char **argv)
// {
// 	int				*unsorted;
// 	t_to_sort		*to_sort;
// 	t_to_sort		*sorted;
// 	t_stack			**stack_a;
// 	unsigned int	i;
	
// 	i = 0;
// 	stack_a = (t_stack **)0;
// 	unsorted = args_validation(argc, argv);
// 	printf("unsorted: ");
// 	while (i < 5)
// 	{
// 		printf("%d ", unsorted[i]);
// 		i++;
// 	}
// 	printf("\n");
// 	to_sort = convert_parsed_to_sort(unsorted, argc, argv);
// 	sorted = sort_bubble(convert_parsed_to_sort(unsorted, argc, argv));
// 	stack_a = make_stack_a(to_sort, sorted, len_by_argc(argc, argv));
// 	// i = 0;
// 	// printf("stack_A: \n");
// 	// while (i < 11)
// 	// {
// 	// 	printf("index: %d ", (*stack_a)->index);
// 	// 	printf("quarter: %d\n", (*stack_a)->quarter);
// 	// 	*stack_a = (*stack_a)->next;
// 	// 	i++;
// 	// }
// 	return (0);
// }