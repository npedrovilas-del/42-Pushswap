#include "push_swap.h"

int	is_sorted(t_sort_stack *a)
{
	t_node	*curr;
	int		i;

	if (a->size < 2)
		return (1);
	curr = a->top;
	i = 0;
	while (i < a->size - 1)
	{
		if (curr->value > curr->next->value)
			return (0);
		curr = curr->next;
		i++;
	}
	return (1);
}
