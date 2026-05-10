#include "push_swap.h"

void	parse_split(char *arg, t_sort_stack *stack_a, t_sort_stack *stack_b)
{
	char	**split_result;
	int		i;

	split_result = ft_split(arg, ' ');
	if (!split_result)
	error_exit(stack_a, stack_b);
	i = 0;
	while (split_result[i])
	{
		if (parse_number(stack_a, split_result[i]))
		{
			i = 0;
			while (split_result[i])
				free(split_result[i++]);
			free(split_result);
			error_exit(stack_a, stack_b);
		}
		i++;
	}
	i = 0;
	while (split_result[i])
		free(split_result[i++]);
	free(split_result);
}

void	parse_input(char **argv, t_bench *bench, t_sort_stack *a, t_sort_stack *b)
{
	int	i;

	if (bench->arg_start >= bench->argc)
		return ;
	if (bench->arg_start != bench->argc - 1)
	{
		i = bench->arg_start;
		while (i < bench->argc)
		{
			if (parse_number(a, argv[i]))
				error_exit(a, b);
			i++;
		}
		return ;
	}
	parse_split(argv[bench->arg_start], a, b);
}

int	strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
