#include "binary_trees.h"

/**
 * avl_node - creates a new avl_t node.
 * @parent: pointer to parent node.
 * @value: integer value for new avl_t node.
 * Return: A pointer to the new avl_t node, or NULL upon failure.
 */
static inline avl_t *avl_node(avl_t *parent, int value)
{
	avl_t *node = malloc(sizeof(*node));

	if (node == NULL)
		exit(12); /* ENOMEM */
	node->n = value;
	node->left = node->right = NULL;
	node->parent = parent;
	return (node);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array.
 * @array: pointer to first element of sorted int[].
 * @size: number of elements in @array.
 * Return: A pointer to the root node of the created AVL, or NULL upon failure.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	static avl_t *root;
	avl_t *node;
	size_t mid = size / 2;

	if (array == NULL || size == 0)
		return (NULL);
	root = node = avl_node(root ? root : NULL, array[mid]);
	node->left = sorted_array_to_avl(array, mid);
	node->right = sorted_array_to_avl(array + mid + 1, size - 1 - mid);
	return (node);
}
