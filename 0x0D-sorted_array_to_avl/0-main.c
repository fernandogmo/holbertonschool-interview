#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * print_array - Prints an array of integers
 * @array: The array to be printed
 * @size: Size of the array
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	for (i = 0; i < size; ++i)
		printf("(%03d)", array[i]);
	printf("\n");
}

/**
 * binary_tree_delete - Deallocate a binary tree
 * @tree: Pointer to the root of the tree to delete
 */
void binary_tree_delete(avl_t *tree)
{
	if (tree)
	{
		binary_tree_delete(tree->left);
		binary_tree_delete(tree->right);
		free(tree);
	}
}

/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, error code on failure
 */
int main(int argc, char **argv)
{
	avl_t *tree;

	if (argc > 1)
	{
		size_t i, sz = argc - 1;
		int *array = malloc(sz * sizeof(*array));

		for (i = 0; i < sz; i++)
		{
			array[i] = atoi(argv[i + 1]);
		}
		tree = sorted_array_to_avl(array, sz);
		if (!tree)
			return (1);
		print_array(array, sz);
		free(array);
	}
	else
	{
		int array[] = {1, 2, 20, 21, 22, 32, 34, 47, 62, 68, 79, 84, 87, 91, 95, 98};
		/* int array[] = {0, 1, 2}; */
		size_t n = sizeof(array) / sizeof(array[0]);

		tree = sorted_array_to_avl(array, n);
		if (!tree)
			return (1);
		print_array(array, n);
	}
	binary_tree_print(tree);
	binary_tree_delete(tree);
	return (0);
}
