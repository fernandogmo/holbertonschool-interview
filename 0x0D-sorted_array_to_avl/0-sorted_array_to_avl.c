#include "binary_trees.h"

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array.
 * @array: A pointer to first element of sorted int[].
 * @size: the number of elements in @array.
 * Return: A pointer to the root node of the created AVL, or NULL upon failure.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array && size)
	{
		size_t mid = size / 2;
		avl_t *root = malloc(sizeof(avl_t));

		if (!root)
			return (NULL);
		root->n = array[mid];
		root->left = sorted_array_to_avl(array, mid);
		root->right = sorted_array_to_avl(array + mid + 1, size - mid - 1);
		root->left ? root->left->parent = root : 0;
		root->right ? root->right->parent = root : 0;
		return (root);
	}
	return (NULL);
}
