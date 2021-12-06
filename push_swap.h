/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:26:52 by shavok            #+#    #+#             */
/*   Updated: 2021/12/06 17:45:37 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct s_list
{
	int				num;
	struct s_list	*next;
	struct s_list	*previous;
}	t_stack;

t_stack	*stack_new_nod(int num);
t_stack	*random_stack(unsigned int stack_size);
void	ft_lstadd_front(t_stack **lst, t_stack *new);

#endif