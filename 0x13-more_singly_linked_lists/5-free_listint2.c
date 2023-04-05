#include "lists.h"

/**
 * free_listint2 - a function that frees a listint_t list
 * @head: pointer to first node
 *
 * Return: no return
 */

void free_listint2(listint_t **head)
{
	listint_t *temp;

	if (head != NULL)
	{

		while ((*head = temp) != NULL)
		{
			temp = (*head)->next;
			free(temp);
		}
		*head = NULL;
	}
}
