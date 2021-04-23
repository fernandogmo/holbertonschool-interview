#include "sort.h"

static size_t sz;

/**
 * sift_down - swaps a node (in a heap array) that is 'too small' with
 * *		its largest child (thereby moving it down) until it is
 * *		at least as large as both nodes below it.
 * @a: int pointer to first element of heap array
 * @root: size_t index of root node
 * @end: size_t limit of heap (in int array @a)
 */
static inline void sift_down(int *a, size_t root, size_t end)
{
	size_t child;
	while ((child = 2 * root + 1) <= end)
	{
		if (child < end && a[child] < a[child + 1]) child++;
		if (a[root] >= a[child]) break;
		SWAP(a[root], a[child]), print_array(a, sz);
		root = child;
	}
}

/**
 * heap_sort - Sorts an array of integers with sift-down algorithm
 * @a: pointer to first element of int array
 * @n: size_t number of elements in @array
 */
void heap_sort(int *a, size_t n)
{
	sz = n; /* set global */
	if (a && n > 1)
	{
		size_t i = (n - 2) / 2;
		while (i--) /* heapify */
			sift_down(a, i, n);
		while (--n)
		{
			SWAP(a[0], a[n]), print_array(a, sz);
			sift_down(a, 0, n - 1);
		}
	}
}
