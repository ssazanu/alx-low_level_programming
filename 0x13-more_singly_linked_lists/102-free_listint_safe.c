#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t linked list.
 * @h: Pointer to a pointer to the head node of the linked list.
 *
 * Return: The number of nodes in the linked list that were freed.
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *current = *h, *next = NULL;
	size_t count = 0;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		count++;

		if (next >= current)
			break;

		current = next;
	}

	*h = NULL;

	return (count);
}

