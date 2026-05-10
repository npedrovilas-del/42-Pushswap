#include "push_swap.h"

int	count_inv_from(t_node *curr, t_node *next, int size)
{
	int	inv;
	int	j;

	inv = 0;
	j = 1;
	while (j < size)
	{
		if (curr->value > next->value)
			inv++;
		next = next->next;
		j++;
	}
	return (inv);
}

double	calculate_disorder(t_sort_stack *a)
{
	t_node	*curr;
	int		inv;
	int		pairs;
	int		i;

	if (a->size <= 1)
		return (0.0);
	inv = 0;
	pairs = a->size * (a->size - 1) / 2;
	curr = a->top;
	i = 0;
	while (i < a->size)
	{
		inv += count_inv_from(curr, curr->next, a->size - i);
		curr = curr->next;
		i++;
	}
	return ((double)inv / pairs);
}

int	choose_algorithm(double disorder)
{
	if (disorder < 0.2)
		return (1);
	else if (disorder < 0.5)
		return (2);
	else
		return (3);
}
