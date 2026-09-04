#include "push_swap.h"

void	sort_complex(t_stack *a, t_stack *b, t_bench *bench)
{
	sort_simple(a, b, bench);
}

void	sort_adaptive(t_stack *a, t_stack *b, t_bench *bench, char **name)
{
	*name = "Simple / O(n^2) [stub]";
	sort_simple(a, b, bench);
}