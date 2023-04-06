#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at index index of a linked list
 * @head: pointer to the first node
 * @index: the index of the node that should be deleted
 *
 * Return: 1 if it succeeded, -1 if it failed
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int i;

	listint_t *first;
	listint_t *second;

	first = *head;

	if (index != 0)
	{
		for (i = 0; i < index - 1 && first != NULL; i++)
		{
			first = first->next;
		}
	}
	if (first == NULL || (first->next == NULL && index != 0))
	{
		return (-1);
	}

	second = first->next;

	if (index != 0)
	{
		first->next = second->next;
		free(second);
	}
	else
	{
		free(first);
		*head = second;
	}

	return (1);
}



