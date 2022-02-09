/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:26:52 by shavok            #+#    #+#             */
/*   Updated: 2022/02/09 11:38:18 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"
# include <stdio.h> // for printf


typedef struct s_stack
{
	unsigned int	index;
	int				quarter;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_to_sort
{
	int					num;
	unsigned int		index;
	struct s_to_sort	*next;
}	t_to_sort;


int				push_swap(int ac, char **av);

long			ft_atoi_long(char *str);
t_stack 		**parsing_args(int argc, char **argv);
int				*args_validation(int argc, char **argv);
int 			*pars_to_unsorted(int *unsorted, int ac, char **av);
int				args_count(char **args);
int 			check_is_digit(char *to_check);
unsigned int	len_by_argc(int argc, char **argv);
t_to_sort 		*convert_parsed_to_sort(int *unsorted, int argc, char **argv);
t_to_sort		*write_to_sort(int *unsodrted, unsigned int len);
t_to_sort		*to_sort_new_node(int num, unsigned int index);
t_to_sort		*to_sort_addnode_back(t_to_sort *to_sort, t_to_sort *new);
t_to_sort		*sort_bubble(t_to_sort *to_sort);
t_to_sort		*sort_radix(t_to_sort *to_sort, int len);
t_stack			**make_stack_a(t_to_sort *unsorted, t_to_sort *sorted, unsigned int len);
t_to_sort		*find_index(t_to_sort *unsorted, t_to_sort *sorted, unsigned int len);
unsigned int	find_quarter(unsigned int index, unsigned int len);

t_stack	*stack_new_node(unsigned int index, unsigned int quarter);
void	stack_nodeadd_back(t_stack **stck, t_stack *new);
void	stack_nodeadd_front(t_stack **stck, t_stack *new);

//operations
void	ops_swap(t_stack **stck, int f);
void	ops_swap_ab(t_stack **stck_a, t_stack **stck_b);
void	ops_push_a(t_stack **stck_a, t_stack **stck_b);
void	ops_push_b(t_stack **stck_a, t_stack **stck_b);
void	ops_rotate(t_stack **stck, int f);
void	ops_rotate_ab(t_stack **stck_a, t_stack **stck_b);
void	ops_rev_rotate(t_stack **stck, int f);
void	ops_rev_rotate_ab(t_stack **stck_a, t_stack **stck_b);


#endif