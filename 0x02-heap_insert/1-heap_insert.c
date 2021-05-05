#include "binary_trees.h"

/**
 * sift_up - swaps value in node (in a heap_t array) with its parent's
 * *	     if it is larger than the parent's value until it is
 * *	     at least as small as its parent's value (or we reach the root)
 * @a: heap_t pointer to one-indexed heap array (a[0] == NULL)
 * @len: size_t length of heap array (NOTE: not its capacity)
 * @last: heap_t pointer to a[len], for convenience
 * Return: heap_t pointer to node we've sifted up
 */
static inline heap_t *sift_up(heap_t **a, size_t len, heap_t *last)
{
	size_t parent = len / 2;
	while (a[parent] && a[parent]->n < last->n)
	{
		SWAP(last->n, a[parent]->n);
		last = a[parent];
		parent /= 2;
	}
	return (last);
}

/**
 * heap_insert - inserts a value in a binary heap
 * *		 (uses static reference array)
 * @root: heap_t double pointer to the root node of the heap's tree
 * @value: int value to insert
 * Return: heap_t pointer to the newly inserted node
 */
heap_t *heap_insert(heap_t **root, int value)
{C99(
	static heap_t *harray[32];
	static size_t hlen;
	if (!*root)
		return (*root = harray[++hlen] = binary_tree_node(NULL, value));
	heap_t *parent = harray[(hlen + 1) / 2];
	harray[++hlen] = (!parent->left)
			? (parent->left = binary_tree_node(parent, value))
			: (parent->right = binary_tree_node(parent, value));
	return (sift_up((heap_t **)&harray, hlen, harray[hlen]));
);}
