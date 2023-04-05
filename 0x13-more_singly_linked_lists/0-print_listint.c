#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint - a function that prints all elements of a list
 * @h: pointer to the first node
 *
 * Return: the number of nodes
 */

size_t print_listint(const listint_t *h)
{
	size_t num = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		num++;
		h = h->next;
	}
	return (num);
}
