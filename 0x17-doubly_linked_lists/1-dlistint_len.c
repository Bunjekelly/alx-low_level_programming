#include "lists.h"
#include <stdlib.h>

/**
 * dlistint_len - a function that returns the number of elements
 * in a linked dlistint_t list
 * @h: pointer to the first element
 *
 * Return: the number of elements
 */

size_t dlistint_len(const dlistint_t *h)
{
	size_t num = 0;

	while (h)
	{
		num++;
		h = h->next;
	}
	return (num);
}
