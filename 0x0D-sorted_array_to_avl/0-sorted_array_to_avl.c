#include "binary_trees.h"
#include <stdio.h>

static avl_t *avl_node(avl_t *parent, int value)
{
	avl_t *node = malloc(sizeof(*node));

	if (!node)
		return (NULL);
	node->n = value;
	node->left = NULL;
	node->right = NULL;
	node->parent = parent;
	return (node);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array.
 * @array: A pointer to first element of sorted int[].
 * @size: the number of elements in @array.
 * Return: A pointer to the root node of the created AVL, or NULL upon failure.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	// static size_t lo, hi;
	static avl_t *root;
	avl_t *parent;

	// hi = hi ? hi : size ? size - 1 : 0;
	// printf("hi = %ld\n", hi), exit(1);
	// if (array && lo <= hi)
	printf("size = %ld\n", size);
	if (array == NULL || size == 0)
		return (NULL);
	/* size_t mid = lo + (hi - lo) / 2; */
	size_t mid = size / 2;

	{
		printf("inner array: ");
		print_array(array, size);
		printf("inner mid = %ld\n", mid);
	}
	parent = avl_node(root ? root : NULL, array[mid]);
	// if (root->parent)
	// 	binary_tree_print(root->parent);
	// else
		printf("New node: "), binary_tree_print(parent);
	{
		// parent = root;
		// while (parent->parent){
		// 	parent = parent->parent;
		// }
		// printf("tree: ");
		// binary_tree_print(parent);
		// printf("lo = %ld, hi = %ld\n", lo, hi);
		// printf("new size = %ld\n", (hi = mid - 1) - lo + 1);
		// printf("lo = %ld, hi = %ld\n", lo, hi);
		// print_array(array, (hi = mid - 1) - lo + 1);
	}
	// save_lo = lo, save_hi = hi;
	// (root)->left = sorted_array_to_avl(array, (hi = mid - 1) - lo + 1);
	printf("ENTERING LEFT with array: ");
	mid ? (void)print_array(array, mid) : (void)puts("nil");
	root = parent;
	parent->left = sorted_array_to_avl(array, mid);
	printf("DONE LEFT with root: "), binary_tree_print(root);
	// printf("lo = %ld, hi = %ld\n", lo, hi);
	// lo = save_lo, hi = save_hi;
	// printf("lo = %ld, hi = %ld\n", lo, hi);
	// (root)->right = sorted_array_to_avl(array, hi - (lo = mid + 1) + 1);
	// root = parent;
	printf("size = %ld, mid = %ld, size - mid = %ld\n", size, mid, size - mid);
	printf("ENTERING RIGHT with array: ");
	// print_array(&array[mid + 1], size - 1 - mid);
	(size - 1 - mid) ? (void)print_array(&array[mid + 1], size - 1 - mid) : (void)puts("nil");
	parent->right = sorted_array_to_avl(array + mid + 1, size - 1 - mid);
	printf("DONE RIGHT with root: "), binary_tree_print(root);
	puts("DID IT WORK?");
	// (void)save_lo, (void)save_hi;
	return (parent);
}
