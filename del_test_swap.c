#include "push_swap.h"

int main()

{
	int i;
	t_stack *stck;
	t_stack *stck1;
	t_stack *new;

	stck = (t_stack *)0;
	stck1 = (t_stack *)0;
	i = 0;
	while (i < 1)
	{
		new = stack_new_nod(i);
		stack_nodadd_back(&stck, new);
		i++;
	}
	i = 2;
	while (i >= 0)
	{
		new = stack_new_nod(i);
		stack_nodadd_back(&stck1, new);
		i--;
	}
	ops_swap_ab(&stck, &stck1);
	// ops_swap(&stck, 1);
	i = 0;
	while (i < 2)
	{
		printf("%d\n", stck->num);
		stck = stck->next;
		i++;
	}
	i = 0;
	while (i < 2)
	{
		printf("%d\n", stck1->num);
		stck1= stck1->next;
		i++;
	}
	return (0);
}