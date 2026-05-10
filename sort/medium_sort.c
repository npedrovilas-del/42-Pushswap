#include "push_swap.h"

t_node	*find_max_in_b(t_sort_stack *b, int *best_pos)
{
	t_node	*curr;
	t_node	*max;
	int		i;

	max = b->top;
	curr = b->top;
	*best_pos = 0;
	i = 0;
	while (i < b->size)
	{
		if (curr->index > max->index)
		{
			max = curr;
			*best_pos = i;
		}
		curr = curr->next;
		i++;
	}
	return (max);
}

void	insert_from_b(t_sort_stack *a, t_sort_stack *b,
		t_bench *bench)
{
	t_node	*max;
	int		best_pos;

	while (b->size > 0)
	{
		max = find_max_in_b(b, &best_pos);
		if (best_pos < b->size / 2)
			while (b->top != max)
				rb(b, bench);
		else
			while (b->top != max)
				rrb(b, bench);
		pa(a, b, bench);
	}
}

void	push_chunk_to_b(t_sort_stack *a, t_sort_stack *b,
		t_chunk *chunk, t_bench *bench)
{
	int	i;
	int	size;

	size = a->size;
	i = 0;
	while (i < size)
	{
		if (in_range(a->top->index, chunk->chunk, chunk->size))
			pb(a, b, bench);
		else
			ra(a, bench);
		i++;
	}
}

void	sort_stack_a(t_sort_stack *a, t_sort_stack *b,
		t_bench *bench)
{
	int		n;
	int		total;
	int		chunk;
	t_chunk	c;

	n = a->size;
	total = (int_sqrt(n) / 2) + 1;
	if (total < 1)
		total = 1;
	c.size = (n + total - 1) / total;
	chunk = 0;
	while (chunk < total && a->size > 0)
	{
		c.chunk = chunk;
		push_chunk_to_b(a, b, &c, bench);
		chunk++;
	}
}

void	medium_algorithm(t_sort_stack *a, t_sort_stack *b,
		t_bench *bench)
{
	sort_stack_a(a, b, bench);
	insert_from_b(a, b, bench);
}
