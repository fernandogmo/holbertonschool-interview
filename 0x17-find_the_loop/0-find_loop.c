#include "lists.h"


/**
 * find_listint_loop - finds start of loop in singly-linked list
 * @head: listint_t pointer
 * Return: The address of the node where the loop starts, or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	for (; head; head = head->next)
		if ((head - head->next) < 0)
			return (head->next);
	return (NULL);
}
