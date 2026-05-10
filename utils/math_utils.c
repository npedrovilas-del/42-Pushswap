#include "push_swap.h"

int	int_sqrt(int n)
{
	int	i;

	i = 1;
	while (i * i < n)
		i++;
	return (i);
}

int	in_range(int index, int chunk, int chunk_size)
{
	int	start;
	int	end;

	start = chunk * chunk_size;
	end = start + chunk_size;
	return (index >= start && index < end);
}
