#include "push_swap.h"

void	print_bench(t_bench *bench, int strategy, double disorder)
{
	int	total;

	total = bench->sa + bench->sb + bench->ss + bench->pa
		+ bench->pb + bench->ra + bench->rb + bench->rr
		+ bench->rra + bench->rrb + bench->rrr;
	fprintf(stderr, "Disorder: %.2f%%\n", disorder * 100);
	if (strategy == 1)
		fprintf(stderr, "Strategy: simple (O(n^2))\n");
	else if (strategy == 2)
		fprintf(stderr, "Strategy: medium (O(n*sqrt(n)))\n");
	else if (strategy == 3)
		fprintf(stderr, "Strategy: complex (O(n log n))\n");
	else
		fprintf(stderr, "Strategy: adaptive\n");
	fprintf(stderr, "Total ops: %d\n", total);
	fprintf(stderr, "sa:%d sb:%d ss:%d pa:%d pb:%d ra:%d "
		"rb:%d rr:%d rra:%d rrb:%d rrr:%d\n",
		bench->sa, bench->sb, bench->ss, bench->pa,
		bench->pb, bench->ra, bench->rb, bench->rr,
		bench->rra, bench->rrb, bench->rrr);
}
