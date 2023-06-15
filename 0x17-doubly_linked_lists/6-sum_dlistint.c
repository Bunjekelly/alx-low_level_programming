#include "lists.h"

/**
 * sum_dlistint - a function that returns the sum of all the data (n)
 * of a doubly linked list
 *
 * @head: pointer to the list
 * Return: sum of the data
 */
int sum_dlistint(dlistint_t *head)
{
	int sum;
	dlistint_t *temp;

	sum = 0;
	temp = head;

	while (temp != NULL)
	{
		sum += temp->n;
		temp = temp->next;
	}
	return (sum);
}
