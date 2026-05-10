#include "push_swap.h"

int	check_duplicates(t_sort_stack *stack, int value)
{
	t_node	*current;
	int		i;

	if (!stack || stack->size == 0)
		return (0);
	current = stack->top;
	i = 0;
	while (i < stack->size)
	{
		if (current->value == value)
			return (1);
		current = current->next;
		i++;
	}
	return (0);
}

int	is_a_number(const char *input)
{
	int	i;

	i = 0;
	if (input[i] == '+' || input[i] == '-')
		i++;
	if (!input[i])
		return (0);
	while (input[i])
	{
		if (input[i] < '0' || input[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	parse_number(t_sort_stack *stack_a, char *str)
{
	long	num;
	t_node	*new;

	if (!is_a_number(str))
		return (1);
	num = ft_atoi(str);
	if (num < INT_MIN || num > INT_MAX)
		return (1);
	if (check_duplicates(stack_a, (int)num))
		return (1);
	new = create_new((int)num);
	if (!new)
		error_exit(stack_a, NULL);
	stack_add_node(stack_a, new);
	return (0);
}

void	error_exit(t_sort_stack *stack_a, t_sort_stack *stack_b)
{
	if (stack_a)
		free_stack(stack_a);
	if (stack_b)
		free_stack(stack_b);
	write(2, "Error\n", 6);
	exit(1);
}

static void	set_strategy(t_bench *bench, int strategy)
{
	if (bench->strategy != 0)
		error_exit(NULL, NULL);
	bench->strategy = strategy;
}

void	parse_flags(int argc, char **argv, t_bench *bench)
{
	int	j;
	j = bench->arg_start;
	while (j < argc && argv[j][0] == '-' && argv[j][1] == '-')
	{
		if (strcmp(argv[j], "--simple") == 0)
			set_strategy(bench, 1);
		else if (strcmp(argv[j], "--medium") == 0)
			set_strategy(bench, 2);
		else if (strcmp(argv[j], "--complex") == 0)
			set_strategy(bench, 3);
		else if (strcmp(argv[j], "--adaptive") == 0)
			set_strategy(bench, 4);
		else if (strcmp(argv[j], "--bench") == 0)
			bench->bench_mode = 1;
		else
			error_exit(NULL, NULL);
		j++;
	}
	bench->arg_start = j;
}
