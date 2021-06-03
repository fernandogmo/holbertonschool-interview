#include "lists.h"

/**
 * find_listint_loop - finds start of loop in singly-linked list
 * @head: listint_t pointer
 * Return: The address of the node where the loop starts, or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *fast, *slow;
	for (fast = slow = head; fast && fast->next;)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			slow = head;
			while (fast != slow)
			{
				fast = fast->next;
				slow = slow->next;
			}
			return (slow);
		}
	}
	return (NULL);
}
