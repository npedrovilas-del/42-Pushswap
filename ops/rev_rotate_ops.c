#include "push_swap.h"

void	rra(t_sort_stack *stack_a, t_bench *bench)
{
	if (!stack_a || stack_a->size < 2)
		return ;
	stack_a->top = stack_a->top->prev;
	if (bench)
		bench->rra++;
	write(1, "rra\n", 4);
}

void	rrb(t_sort_stack *stack_b, t_bench *bench)
{
	if (!stack_b || stack_b->size < 2)
		return ;
	stack_b->top = stack_b->top->prev;
	if (bench)
		bench->rrb++;
	write(1, "rrb\n", 4);
}

void	rrr(t_sort_stack *stack_a, t_sort_stack *stack_b, t_bench *bench)
{
	if (stack_a && stack_a->size >= 2)
		stack_a->top = stack_a->top->prev;
	if (stack_b && stack_b->size >= 2)
		stack_b->top = stack_b->top->prev;
	if (bench)
		bench->rrr++;
	write(1, "rrr\n", 4);
}
