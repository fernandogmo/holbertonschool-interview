#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: pointer to first node in sorted singly linked list
 * @number: value of new node
 * Return: address of the new node or NULL on failure
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *prev = NULL, *ptr = (head) ? *head : NULL;

	while (ptr && ptr->n < number)
	{
		prev = ptr;
		ptr = ptr->next;
	}
	if (prev || ptr)
	{
		listint_t *new = malloc(sizeof(*new));

		if (!new)
			return (NULL);
		new->n = number;
		new->next = ptr;
		if (prev)
			prev->next = ptr = new;
		else
			*head = ptr = new;
	}

	return (ptr);
}
