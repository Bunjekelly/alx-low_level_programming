#include "lists.h"

/**
 * free_listint - frees a list
 * @head: pointer to first element
 *
 * Return: no return
 */

void free_listint(listint_t *head)
{
	listint_t *temp;

	temp = head;

	while (temp != NULL)
	{
		head = head->next;
		free(temp);
	}
}
