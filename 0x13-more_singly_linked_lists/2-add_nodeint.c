#include "lists.h"

/**
 * add_nodeint - adds a new node the beginning of list
 * @head: head of list
 * @n: data for the new node
 * @new: new node to be added
 *
 * Return: the address of the new element, or NULL if it failed
 */

listint_t *add_nodeint(listint_t **head, const int n)
{

	listint_t *new;

	new = malloc(sizeof(listint_t));

	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = *head;
	*head = new;

	return (new);
}
