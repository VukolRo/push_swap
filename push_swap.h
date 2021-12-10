/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:26:52 by shavok            #+#    #+#             */
/*   Updated: 2021/12/10 17:37:39 by shavok           ###   ########.fr       */
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
	int				num;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

t_stack	*pars_args(int argc, char **argv);

t_stack	*stack_new_nod(int numbr);
void	stack_nodadd_front(t_stack **stck, t_stack *new);
void	stack_nodadd_back(t_stack **stck, t_stack *new);

void	ops_swap(t_stack **stck, int f);
void	ops_swap_ab(t_stack **stck_a, t_stack **stck_b);
void	ops_push_a(t_stack **stck_a, t_stack **stck_b);
void	ops_push_b(t_stack **stck_a, t_stack **stck_b);



#endif