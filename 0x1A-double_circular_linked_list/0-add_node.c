#include "list.h"

#pragma GCC diagnostic ignored "-Wpedantic"

/**
 * node_create - desc
 * @str: str
 * Return: created node
 */
static List *node_create(char *str)
{
	List *new = malloc(sizeof(*new));
	if (!new) return (NULL);
	new->str = strdup(str);
	if (!new->str) {free(new); return (NULL);}
	return (new);
}

/**
 * add_node_begin - desc
 * @list: list
 * @str: str
 * Return: pointer to new List node, or NULL if failed
 */
List *add_node_begin(List **list, char *str)
{
	List *new = node_create(str);
	if (!new) return (NULL);

	if (!*list)
	{
		*list = new;
		(*list)->next = (*list)->prev = new;
		return (new);
	}

	List *last = (*list)->prev;
	new->next = *list;
	new->prev = last;
	last->next = (*list)->prev = new;
	*list = new;
	return (new);
}

/**
* add_node_end - desc
* @list: list
* @str: str
* Return: pointer to new List node, or NULL if failed
*/
List *add_node_end(List **list, char *str)
{
	return (add_node_begin(list, str) ? *list = (*list)->next : NULL);
}
