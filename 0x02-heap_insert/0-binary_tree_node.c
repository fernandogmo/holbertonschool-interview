#include <stdlib.h>
#include <string.h>

#include "binary_trees.h"

/**
 * binary_tree_node - creates a node with no children
 * @parent: parent node to new node
 * @value: key value of new node
 * Return: pointer to new node or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{C99(
	binary_tree_t src = (binary_tree_t){value, parent, NULL, NULL};
	binary_tree_t *dst = calloc(1, sizeof(*dst));
	if (!dst) return (NULL);
	return (memcpy(dst, &src, sizeof(src)));
);}
