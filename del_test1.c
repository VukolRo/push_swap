# include "./libft/libft.h"
# include <stdio.h> // for printf

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;


t_stack	*stack_new_nod(int numbr)

{
	t_stack	*e1;

	e1 = (t_stack *)0;
	e1 = (t_stack *)malloc(sizeof(t_stack));
	if (e1)
	{
		e1->num = numbr;
		e1->next = e1;
		e1->prev = e1;
	}
	return (e1);
}

void	stack_nodadd_back(t_stack **lst, t_stack *new)

{
	t_stack *tmp_f;
	t_stack *tmp_l;

	if (new)
	{
		if (!(*lst))
		{
			*lst = new;
		}
		else
		{
			tmp_f = *lst;
			tmp_l = (*lst)->prev;
			new->next = tmp_f;
			tmp_l->next = new;
			new->prev = tmp_l;
			(*lst)->prev = new;
		}
	}
}


int main()

{
	t_stack *st_a;
	t_stack *st_b;
	t_stack *st_c;
	int		i;

	i = 0;
	st_a = stack_new_nod(1);
	st_b = stack_new_nod(2);

	stack_nodadd_back(&st_a, st_b);
	st_c = stack_new_nod(3);
	stack_nodadd_back(&st_a, st_c);

	while (i < 10)
	{
		printf("%d\n", st_a->num);
		st_a = st_a->prev;
		i++;
	}
	return (0);
}