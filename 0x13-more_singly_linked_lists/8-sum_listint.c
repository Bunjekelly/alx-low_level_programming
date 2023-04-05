#include "lists.h"

/**
 * sum_listint - returns sum of all data of a list
 * @head: pointer to the first node
 *
 * Return: sum of data or 0.
 */

int sum_listint(listint_t *head)
{
	int sum = 0;


	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
