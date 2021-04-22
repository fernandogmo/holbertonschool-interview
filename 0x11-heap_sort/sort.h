#ifndef SORT_H
#define SORT_H

#include <stddef.h>

void heap_sort(int *a, size_t n);
void print_array(const int *a, size_t n);

#define SWAP(a, b)                   \
	do                           \
	{                            \
		const int tmp = (a); \
		(a) = (b);           \
		(b) = tmp;           \
	} while (0)

#endif /* SORT_H */
