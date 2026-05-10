#include "push_swap.h"

void	pa(t_sort_stack *stack_a, t_sort_stack *stack_b,
		t_bench *bench)
{
	t_node	*node;

	if (!stack_b || stack_b->size == 0)
		return ;
	node = stack_pop_top(stack_b);
	stack_push_top(stack_a, node);
	if (bench)
		bench->pa++;
	write(1, "pa\n", 3);
}

void	pb(t_sort_stack *stack_a, t_sort_stack *stack_b,
		t_bench *bench)
{
	t_node	*node;

	if (!stack_a || stack_a->size == 0)
		return ;
	node = stack_pop_top(stack_a);
	stack_push_top(stack_b, node);
	if (bench)
		bench->pb++;
	write(1, "pb\n", 3);
}
