#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list.
 * @head: Pointer to the head node of the linked list.
 *
 * Return: The number of nodes in the linked list.
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *current = head, *prev = NULL;
	size_t count = 0;

	while (current != NULL)
	{
		printf("[%p] %d\n", (void *)current, current->n);
		count++;

		if (current < prev)
			break;

		prev = current;
		current = current->next;
	}

	if (current != NULL)
	{
		printf("-> [%p] %d\n", (void *)current, current->n);
		exit(98);
	}

	return (count);
}

