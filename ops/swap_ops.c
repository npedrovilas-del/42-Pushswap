#include "push_swap.h"

void	sa(t_sort_stack *stack_a, t_bench *bench)
{
	if (!stack_a || stack_a->size < 2)
		return ;
	swap_nodes(stack_a);
	if (bench)
		bench->sa++;
	write(1, "sa\n", 3);
}

void	sb(t_sort_stack *stack_b, t_bench *bench)
{
	if (!stack_b || stack_b->size < 2)
		return ;
	swap_nodes(stack_b);
	if (bench)
		bench->sb++;
	write(1, "sb\n", 3);
}

void	swap_nodes(t_sort_stack *stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	last = first->prev;
	if (stack->size == 2)
	{
		stack->top = second;
	}
	else
	{
		first->next = second->next;
		first->prev = second;
		second->next = first;
		second->prev = last;
		last->next = second;
		stack->top = second;
	}
}

void	ss(t_sort_stack *stack_a, t_sort_stack *stack_b,
		t_bench *bench)
{
	if (stack_a && stack_a->size >= 2)
		swap_nodes(stack_a);
	if (stack_b && stack_b->size >= 2)
		swap_nodes(stack_b);
	if (bench)
		bench->ss++;
	write(1, "ss\n", 3);
}
