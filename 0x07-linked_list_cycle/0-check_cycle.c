#include "lists.h"

/**
 * check_cycle - detects a cycle in a linked list by
 **		 Floyd's cycle detection algorithm
 * @head: pointer to head of a listint_t
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *head)
{
	listint_t *a = head, *b = head->next;

	while (b->next)
	{
		a = a->next;
		b = b->next->next;
		if (a == b)
			return (1);
	}
	return (0);
}
