#include "push_swap.h"

void	simple_algorithm(t_sort_stack *stack_a,
		t_sort_stack *stack_b, t_bench *bench)
{
	t_node	*temp;
	t_node	*min;
	int		i;

	while (stack_a->size > 0)
	{
		temp = stack_a->top;
		min = temp;
		i = 0;
		while (i < stack_a->size)
		{
			if (temp->value < min->value)
				min = temp;
			temp = temp->next;
			i++;
		}
		while (stack_a->top != min)
			ra(stack_a, bench);
		pb(stack_a, stack_b, bench);
	}
	while (stack_b->size > 0)
		pa(stack_a, stack_b, bench);
}
