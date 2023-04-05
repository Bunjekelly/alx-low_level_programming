#include "lists.h"

/**
 * pop_listint - deletes the head node of a limked list
 * @head: pointer to first node
 *
 * Return: the head node’s data (n) or 0.
 */

int pop_listint(listint_t **head)
{
	listint_t *temp;
	int num;

	if (head == NULL || (*head) == NULL)
	{
		return (0);
	}
	else
	{
		num = (*head)->n;
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}
	return (num);
}
