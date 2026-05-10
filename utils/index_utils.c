#include "push_swap.h"

int	*sort_index(int *array, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (array);
}

void	atribute_indexs(t_sort_stack *stack_a, int *array)
{
	int		i;
	int		f;
	t_node	*node;

	node = stack_a->top;
	i = 0;
	while (i < stack_a->size)
	{
		f = 0;
		while (f < stack_a->size)
		{
			if (node->value == array[f])
			{
				node->index = f;
				break;
				
			}
			f++;
		}
		node = node->next;
		i++;
	}
}

void	list_index(t_sort_stack *stack_a)
{
	int		*indexs;
	int		i;
	t_node	*node;

	i = 0;
	indexs = malloc(sizeof(int) * stack_a->size);
	if (!indexs)
		error_exit(stack_a, NULL);
	node = stack_a->top;
	while (i < stack_a->size)
	{
		indexs[i] = node->value;
		node = node->next;
		i++;
	}
	indexs = sort_index(indexs, stack_a->size);
	atribute_indexs(stack_a, indexs);
	free(indexs);
}
