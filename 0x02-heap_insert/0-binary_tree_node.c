#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "binary_trees.h"

/**
 * binary_tree_node - creates a node with no children
 * @parent: parent node to new node
 * @value: key value of new node
 * Return: pointer to new node or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new = malloc(sizeof(*new));

	if (!new)
		return (NULL);
	new->n = value;
	new->parent = parent;

	return (new);
}

/**
 *
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new = NULL;

	return (new = binary_tree_node(*root, value));
}
