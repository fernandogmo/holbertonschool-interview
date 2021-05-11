#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * sift_down - restores max heap property from root node of subtree
 * @root: binary_tree_t root root of heap tree
 */
static void sift_down(binary_tree_t *root)
{
	if (!root || !root->left) return;

	if (root->right && root->left->n < root->right->n)
	{
		if (root->n <= root->right->n)
			SWAP(root->n, root->right->n);
		sift_down(root->right);
	}
	else
	{
		if (root->n <= root->left->n)
			SWAP(root->n, root->left->n);
		sift_down(root->left);
	}
}

/**
 * heap_to_array - it does this while calculating heap size
 * @array: binary_tree_t buffer where we are storing our heap elements
 * @root: root binary_tree_t of our heap subtree
 * @i: size_t index of subtree's @root node
 * Return: size_t size of heap. the same as the length of @array
 */
static size_t heap_to_array(binary_tree_t **array,
			    binary_tree_t *root,
			    size_t i)
{
	return (!root || !array || !(array[i] = root)
		? 0 : 1 + heap_to_array(array, root->left, 2 * i + 1)
			+ heap_to_array(array, root->right, 2 * i + 2));
}

/**
 * heap_extract - extracts the root value of a binary heap
 * @root: heap_t pointer
 * Return: int data that was stored in heap's root
 */
int heap_extract(heap_t **root)
{C99(
	if (!root || !*root) return (0);

	binary_tree_t *a[32], *last;
	int data = (*root)->n;

	size_t len = heap_to_array((binary_tree_t **)&a, *root, 0);

	if (*root == (last = a[len - 1]))
		*root = NULL;
	else
	{
		(*root)->n = last->n;
		if (last->parent->left == last)
			last->parent->left = NULL;
		else
			last->parent->right = NULL;
		sift_down(*root);
	}
	free(last);
DBG(printf("heap size now %ld\n\n", len));
	return (data);
);}
