#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    listint_t *head;

    head = NULL;
    add_nodeint_end(&head, 0);
    add_nodeint_end(&head, 1);
    add_nodeint_end(&head, 2);
    add_nodeint_end(&head, 3);
    add_nodeint_end(&head, 4);
    add_nodeint_end(&head, 98);
    add_nodeint_end(&head, 402);
    add_nodeint_end(&head, 1024);
    print_listint(head);

    printf("------- insert into beginning, middle, and end ----------\n");

    insert_node(&head, -2);
    insert_node(&head, 27);
    insert_node(NULL, 42); /* new list created, 16 bytes lost in 1 block */
    insert_node(&head, 27);
    insert_node(&head, 1025);

    print_listint(head);

    free_listint(head);

    printf("------- insert into empty linked list -------------------\n");

    head = NULL;
    insert_node(&head, 42);
    print_listint(head);

    free_listint(head);

    return (0);
}
