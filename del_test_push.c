#include "push_swap.h"

int main()

{
	int i;
	t_stack *stck;
	t_stack *stck1;
	t_stack *new;

	stck = (t_stack *)0;
	stck1 = (t_stack *)0;

	// new = stack_new_nod(30);
	// stack_nodadd_back(&stck, new);
	// i = 0;
	// while (i < 5)
	// {
	// 	new = stack_new_nod(i);
	// 	stack_nodadd_back(&stck, new);
	// 	i++;
	// }

	// new = stack_new_nod(30);
	// stack_nodadd_back(&stck1, new);
	i = 5;
	while (i > 0)
	{
		new = stack_new_nod(i);
		stack_nodadd_back(&stck1, new);
		i--;
	}
	ops_push_a(&stck, &stck1);
	// ops_push_b(&stck, &stck1);
	i = 0;
	printf("stack A\n");
	while (i < 3)
	{
		printf("%d\n", stck->num);
		stck = stck->next;
		i++;
	}
	i = 0;
	printf("stack B\n");
	while (i < 6)
	{		
		printf("%d\n", stck1->num);
		stck1= stck1->next;
		i++;
	}
	// new = stack_new_nod(30);
	// stack_nodadd_back(&stck1, new);
	// i = 0;
	// printf("stack B\n");
	// while (i < 3)
	// {		
	// 	printf("%d\n", stck1->num);
	// 	stck1= stck1->next;
	// 	i++;
	// }

	// i = 0;
	// printf("stack A\n");
	// while (i < 5)
	// {
	// 	printf("%d\n", stck->num);
	// 	stck = stck->next;
	// 	i++;
	// }
	return (0);
}