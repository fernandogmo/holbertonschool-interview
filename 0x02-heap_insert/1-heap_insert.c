#include <stdlib.h>
#include "binary_trees.h"

/**
 * swap_node - swaps nodes
 * @a: one node to swap
 * @b: other node to swap
 */
void swap_node(heap_t **a, heap_t **b)
{
	heap_t *tmp = *a;

	*a = *b;
	*b = tmp;
}

/**
 * heap_insert - inserts a new node in max heap ordering
 * @root: root of heap
 * @value: key value of new node
 * Return: pointer to new node or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new = NULL, *h = (root) ? *root : NULL;

	if (!root)
		return (NULL);
	if (h == NULL)
		*root = new = binary_tree_node(h, value);
	else if (h->n < value)
	{
		if (!h->left)
		{
			new = binary_tree_node(h->parent, value);
			swap_node(&new->left, &h->left);
			swap_node(&new->right, &h->right);
			new->left = h;
			if (!h->parent)
				*root = h->parent = new;
			else if (h->parent->left == h)
			{
				h->parent->left = new;
				h->parent = new;
			}
			else
			{
				h->parent->right = new;
				h->parent = new;
			}
		}
		else if (!h->right)
		{
			new = binary_tree_node(h->parent, value);
			swap_node(&new->left, &h->left);
			swap_node(&new->right, &h->right);
			new->right = h;
			if (!h->parent)
				*root = h->parent = new;
			else if (h->parent->left == h)
			{
				h->parent->left = new;
				h->parent = new;
			}
			else
			{
				h->parent->right = new;
				h->parent = new;
			}
		}
	}
	else if (h->n > value)
	{
		if (!h->left)
		{
			new = heap_insert(&h->left, value);
			new->parent = h;
		}
		else if (!h->right)
		{
			new = heap_insert(&h->right, value);
			new->parent = h;
		}
		else
			new = heap_insert(&h->left, value);
	}

	return (new);
}
