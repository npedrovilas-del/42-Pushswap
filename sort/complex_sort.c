#include "push_swap.h" 

static void	process_bit(t_sort_stack *a, t_sort_stack *b, int bit, int size, t_bench *bench)
{
	int	i;
	i = 0;
	while (i < size)
	{
		if (((a->top->index >> bit) & 1) == 0)
			pb(a, b, bench);
		else
			ra(a, bench);
		i++;
	}
}
void	complex_algorithm(t_sort_stack *a, t_sort_stack *b, t_bench *bench)
{
	int	max_bits;
	int	size;
	int	bit;
	size = a->size;
	max_bits = 0;
	while ((size >> max_bits) != 0)
		max_bits++;
	bit = 0;
	while (bit < max_bits)
	{
		process_bit(a, b, bit, size, bench);
		while (b->size > 0)
			pa(a, b, bench);
		bit++;
	}
}