#include "push_swap.h"

void	ra(t_sort_stack *stack_a, t_bench *bench)
{
	if (!stack_a || stack_a->size < 2)
		return ;
	stack_a->top = stack_a->top->next;
	if (bench)
		bench->ra++;
	write(1, "ra\n", 3);
}

void	rb(t_sort_stack *stack_b, t_bench *bench)
{
	if (!stack_b || stack_b->size < 2)
		return ;
	stack_b->top = stack_b->top->next;
	if (bench)
		bench->rb++;
	write(1, "rb\n", 3);
}

void	rr(t_sort_stack *stack_a, t_sort_stack *stack_b,
		t_bench *bench)
{
	if (stack_a && stack_a->size >= 2)
		stack_a->top = stack_a->top->next;
	if (stack_b && stack_b->size >= 2)
		stack_b->top = stack_b->top->next;
	if (bench)
		bench->rr++;
	write(1, "rr\n", 3);
}
