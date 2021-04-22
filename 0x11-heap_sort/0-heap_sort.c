#include "sort.h"
#include <stdio.h>

static size_t sz;

static void sift_down(int *a, size_t n, size_t i)
{
	while (1)
	{
		size_t j = 2 * i + 1;
		size_t k = j + 1;
		size_t m = (j < n) && a[j] > a[i] ? j : i;

		m = (k < n && a[k] > a[m]) ? k : m;
		if (m == i)
			break;
		SWAP(a[i], a[m]);
		i = m;
		print_array(a, sz);
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

		while (i-- > 0)
			sift_down(a, n, i);
		while (--n)
		{
			SWAP(a[0], a[n]);
			print_array(a, sz);
			sift_down(a, n, 0);
		}
	}
}
