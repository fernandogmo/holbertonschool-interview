#include <stdlib.h>

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
	new->left = new->right = NULL;

	return (new);
}
