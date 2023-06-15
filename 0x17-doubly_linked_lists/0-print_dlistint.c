#include "lists.h"

/**
 * print_dlistint -  a function that prints all the elements
 * of a dlistint_t list.
 * @h: pointer to the list
 *
 * Return: the number of nodes
 */

size_t print_dlistint(const dlistint_t *h)
{
	unsigned int num = 0;

	if (h == NULL)
		return (num);

	while (h->prev != NULL)
		h = h->prev;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		num++;
		h = h->next;
	}
	return (num);
}
