#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: pointer to first node
 * @number: value of new node
 * Return: address of the new node or NULL on failure
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *prev = NULL, *ptr = (head) ? *head : NULL;
	listint_t *new = malloc(sizeof(*new));

	if (!new || !head)
		return (NULL);
	while (ptr && ptr->n < number)
		ptr = (prev = ptr)->next;
	new->n = number;
	new->next = ptr;
	if (prev)
		prev->next = new;
	else
		*head = new;

	return (new);
}
