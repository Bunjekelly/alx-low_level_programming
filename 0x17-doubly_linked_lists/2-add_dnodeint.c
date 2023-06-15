#include "lists.h"
#include <stdlib.h>

/**
 * add_dnodeint -  adds a new node at the beginning of a dlistint_t list
 * @head: double pointer to list
 * @n: data to be added
 *
 * Return:  address of the new element, or NULL if it failed
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;

	new = malloc(sizeof(dlistint_t));

	if (!new)
		return (NULL);
	
	new->n = n;
	new->prev = NULL;

	if ((*head) != NULL)
	{
		new->next = (*head);
		(*head)->prev = new;
	}
	(*head) = new;

	return (*head);
}
