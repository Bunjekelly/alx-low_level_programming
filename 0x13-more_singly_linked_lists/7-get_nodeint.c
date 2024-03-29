#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node of a listint_t linked list
 * @head: pointer to first node
 * @index: the index of the node, starting at 0
 *
 * Return: the nth node of the list or NULL
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{

	unsigned int i;

	for (i = 0; i < index; i++)
	{
		if (head == NULL)
			return (NULL);
		head = head->next;
	}

	return (head);
}
