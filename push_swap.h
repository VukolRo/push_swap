/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:26:52 by shavok            #+#    #+#             */
/*   Updated: 2022/01/21 18:25:17 by shavok           ###   ########.fr       */
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
	unsigned int	scr_r_a;
	unsigned int	scr_rr_a;
	unsigned int	scr_r_b;
	unsigned int	scr_rr_b;
	unsigned int	min_rr;
	unsigned int	min_rrr;
	unsigned int	min_ra_rrb;
	unsigned int	min_rra_rb;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

// typedef struct s_num_lst
// {
// 	int					num;
// 	struct s_num_lst	*next;
// }	t_num_lst;

t_stack *push_swap(int ac, char **av);


t_stack	*pars_args(int argc, char **argv);
int	check_if_full_srtd(t_stack *stck);
int	check_if_srtd(t_stack *stck);

t_stack	*stack_new_nod(int numbr);
void	stack_nodadd_front(t_stack **stck, t_stack *new);
void	stack_nodadd_back(t_stack **stck, t_stack *new);

void	ops_swap(t_stack **stck, int f);
void	ops_swap_ab(t_stack **stck_a, t_stack **stck_b);
void	ops_push_a(t_stack **stck_a, t_stack **stck_b);
void	ops_push_b(t_stack **stck_a, t_stack **stck_b);
void	ops_rotate(t_stack **stck, int f);
void	ops_rotate_ab(t_stack **stck_a, t_stack **stck_b);
void	ops_rev_rotate(t_stack **stck, int f);
void	ops_rev_rotate_ab(t_stack **stck_a, t_stack **stck_b);


#endif