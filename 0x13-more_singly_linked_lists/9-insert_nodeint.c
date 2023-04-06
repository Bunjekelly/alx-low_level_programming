#include "lists.h"

/**
 * insert_nodeint_at_index - inserts node at given position
 * @head: pointer to first node
 * @idx: new index where node will be added
 * @n: data of new node
 *
 * Return: the address of the new node, or NULL if it failed
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i;
	listint_t *new;
	listint_t *temp;

	temp = *head;

	new = malloc(sizeof(listint_t));

	if (new == NULL)
		return (NULL);
	new->n =n;

	if (idx != 0)
	{
		for (i = 0; (i < (idx - 1) && temp != NULL); i++)
		{
			temp = temp->next;
		}
	}
	if (temp == NULL && idx != 0)
		return (NULL);
	if (idx == 0)
	{
		new->next = *head;
		*head = new;
	}
	else
	{
		new->next = temp->next;
		temp->next = new;
	}
	return (new);
}
