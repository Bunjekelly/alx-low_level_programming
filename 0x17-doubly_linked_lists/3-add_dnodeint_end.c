#include "lists.h"
#include <stdlib.h>

/**
 * add_dnodeint_end - a function that adds a new node
 * at the end of a dlistint_t list
 * @head: double pointer to list
 * @n: data to be added
 *
 * Return: the address of the new element, or NULL if it failed
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new;
	dlistint_t *current;

	new = malloc(sizeof(dlistint_t));

	if (!new)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
	}
	else
		current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
	new->prev = current;
}
