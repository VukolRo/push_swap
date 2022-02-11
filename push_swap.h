/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:05:46 by shavok            #+#    #+#             */
/*   Updated: 2022/02/11 22:36:58 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h> // для printf (после удалить)
# include <stdlib.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648

// структура листа
typedef struct s_node
{
	unsigned int	index;
	int				quarter;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_all
{
	t_node			*stack_a;
	t_node			*stack_b;
	unsigned int	size_a;
	unsigned int	size_b;
	int				min;
	int				med;
	int				max;
	int				min_a;
}					t_all;

// push_swap.c
t_all	*stack_create(char **argv);
void	sorting(t_all *all);
int	chech_if_full_sorted(t_all *all);
int	chech_if_sorted(t_all *all);

// parsing_args.c
char	**parsing_args(char **argv);
void	args_validating(char **arr);
void	free_arr(char **arr, int flag);
void	free_stack(t_all *all);
void	check_if_doublicated(char **arr);

// fill_stack.c
t_all	*fill_stack(char **arr);
void	create_struct(t_all *all, char **arr);
void	find_index(t_all *all, char **arr);
void	bubble_sorting(int *sorted, unsigned int len);
void	fill_index(t_all *all, int *unsorted, int *sorted);

// node_add.c
t_node	*node_new(int index, int quarter);
void	node_add_back(t_node **stack, t_node *new);
int		find_quarter(unsigned int index, unsigned int len);

// easy_sort.c
void	easy_sort(t_all *all);
void	sort_for_three(t_all *all);

// ops_rotation.c
void	ops_rev_rotate(t_all *all, int flag, unsigned int count);
void	ops_rotate(t_all *all, int flag, unsigned int count);
void	ops_rev_rotate_ab(t_all *all, unsigned int count);
void	ops_rotate_ab(t_all *all, unsigned int count);

// ops_swap.c
void ops_swap_a(t_all *all);
void ops_swap_b(t_all *all);
void ops_swap_ab(t_all *all);


// ops_push.c
void	ops_push(t_all *all, int flag, unsigned int count);
void	ops_pa(t_all *all, unsigned int count);
void	ops_pb(t_all *all, unsigned int count);



// ft_atoi_long.c
long	ft_atoi_long(char *str);

#endif