#include "lists.h"

/**
 * reverse_listint - a function that reverses a listint_t linked list
 * @head: pointer to first node
 *
 * Return: a pointer to the first node of the reversed list
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *a;
	listint_t *z;

	if (head == NULL || *head == NULL)
		return (NULL);

	z = NULL;

	while ((*head)->next != NULL)
	{
		a = (*head)->next;
		(*head)->next = z;
		z = *head;
		*head = a;
	}
	(*head)->next = z;

	return (*head);
}
