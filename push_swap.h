#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

typedef struct s_node
{
	int				index;
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_sort_stack
{
	int		size;
	t_node	*top;
}	t_sort_stack;

typedef struct s_bench
{
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		strategy;
	int		bench_mode;
	int		argc;
	int		arg_start;
}	t_bench;

typedef struct s_chunk
{
	int	chunk;
	int	size;
}	t_chunk;

t_node	*create_new(int value);
void	stack_add_node(t_sort_stack *stack, t_node *new_node);
void	sa(t_sort_stack *stack_a, t_bench *bench);
void	sb(t_sort_stack *stack_b, t_bench *bench);
void	swap_nodes(t_sort_stack *stack);
void	ss(t_sort_stack *stack_a, t_sort_stack *stack_b, t_bench *bench);
void	stack_push_top(t_sort_stack *stack, t_node *node);
t_node	*stack_pop_top(t_sort_stack *stack);
void	pa(t_sort_stack *stack_a, t_sort_stack *stack_b, t_bench *bench);
void	pb(t_sort_stack *stack_a, t_sort_stack *stack_b, t_bench *bench);
void	ra(t_sort_stack *stack_a, t_bench *bench);
void	rb(t_sort_stack *stack_b, t_bench *bench);
void	rr(t_sort_stack *stack_a, t_sort_stack *stack_b, t_bench *bench);
void	rra(t_sort_stack *stack_a, t_bench *bench);
void	rrb(t_sort_stack *stack_b, t_bench *bench);
void	rrr(t_sort_stack *stack_a, t_sort_stack *stack_b, t_bench *bench);
int		check_duplicates(t_sort_stack *stack, int value);
int		is_a_number(const char *input);
int		parse_number(t_sort_stack *stack_a, char *str);
void	parse_flags(int argc, char **argv, t_bench *bench);
void	parse_split(char *arg, t_sort_stack *stack_a, t_sort_stack *stack_b);
void	parse_input(char **argv, t_bench *bench, t_sort_stack *a, t_sort_stack *b);
long	ft_atoi(const char *str);
char	**ft_split(const char *s, char c);
int		strcmp(const char *s1, const char *s2);
void	free_stack(t_sort_stack *stack);
void	error_exit(t_sort_stack *stack_a, t_sort_stack *stack_b);
int		choose_algorithm(double disorder);
void	atribute_indexs(t_sort_stack *stack_a, int *array);
void	list_index(t_sort_stack *stack_a);
int		*sort_index(int *array, int size);
int		is_sorted(t_sort_stack *a);
void	simple_algorithm(t_sort_stack *a, t_sort_stack *b,
			t_bench *bench);
void	medium_algorithm(t_sort_stack *a, t_sort_stack *b,
			t_bench *bench);
void	sort_stack_a(t_sort_stack *a, t_sort_stack *b,
			t_bench *bench);
void	push_chunk_to_b(t_sort_stack *a, t_sort_stack *b,
			t_chunk *chunk, t_bench *bench);
void	insert_from_b(t_sort_stack *a, t_sort_stack *b,
			t_bench *bench);
t_node	*find_max_in_b(t_sort_stack *b, int *best_pos);
void	complex_algorithm(t_sort_stack *a, t_sort_stack *b,
			t_bench *bench);
double	calculate_disorder(t_sort_stack *a);
int		count_inv_from(t_node *curr, t_node *next, int size);
void	print_bench(t_bench *bench, int strategy, double disorder);
int		int_sqrt(int n);
int		in_range(int index, int chunk, int chunk_size);
void	init_stacks(t_bench *bench, int argc);
void	run_algorithm(t_sort_stack *a, t_sort_stack *b, int strategy, t_bench *bench, double disorder);
#endif
