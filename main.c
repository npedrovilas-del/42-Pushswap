#include "push_swap.h"

void	init_stacks(t_bench *bench, int argc)
{
	*bench = (t_bench){0};
	bench->argc = argc;
	bench->arg_start = 1;
}

void	run_algorithm(t_sort_stack *a, t_sort_stack *b, int strategy, t_bench *bench, double disorder)
{
	if (strategy == 1)
		simple_algorithm(a, b, bench);
	else if (strategy == 2)
		medium_algorithm(a, b, bench);
	else if (strategy == 3)
		complex_algorithm(a, b, bench);
	else
	{
		strategy = choose_algorithm(disorder);
		run_algorithm(a, b, strategy, bench, disorder);
	}
}
int	main(int argc, char **argv)
{
	t_sort_stack	stack_a;
	t_sort_stack	stack_b;
	t_bench			bench;
	double			disorder;

	if (argc < 2)
		return (0);
	stack_a = (t_sort_stack){0};
	stack_b = (t_sort_stack){0};
	init_stacks(&bench, argc);
	parse_flags(argc, argv, &bench);
	parse_input(argv, &bench, &stack_a, &stack_b);
	list_index(&stack_a);
	disorder = calculate_disorder(&stack_a);
	if (!is_sorted(&stack_a))
		run_algorithm(&stack_a, &stack_b, bench.strategy, &bench, disorder);
	if (bench.bench_mode)
		print_bench(&bench, bench.strategy, disorder);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
