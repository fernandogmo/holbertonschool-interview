#include <stdio.h>
#include "search_algos.h"

/**
 * advanced_binary - searches for a value in an array of ints
 * @array: ptr to the first element of the array to search
 * @sz: number of elements in @array
 * @v: value to find in @array
 * Return: first index where value is located,
 *         or -1 if value not present or array is NULL
 */
int advanced_binary(int *array, size_t sz, int v)
{
	static size_t l, u;

	u = u ? u : sz ? sz - 1 : 0;
	if (array && l <= u)
	{
		size_t i = l, m = l + (u - l) / 2;

		printf("Searching in array: ");
		while (i < u)
			printf("%d, ", array[i++]);
		printf("%d\n", array[i]);

		if (array[m] == v)
			return ((m > 0 && array[m - 1] == v)
				? advanced_binary(array, SZ_NEW_U, v)
				: (int)(m + RESET_STATICS));
		else if (array[m] < v)
			return (advanced_binary(array, SZ_NEW_L, v));
		else if (array[m] > v)
			return (advanced_binary(array, SZ_NEW_U, v));
	}
	return (-1 + RESET_STATICS);
}
