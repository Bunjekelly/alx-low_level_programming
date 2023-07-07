#include "hash_tables.h"
#include <string.h>
#include <stdlib.h>

/**
 * hash_table_set -  adds an element to the hash table
 * @ht: pointer to the hash table.
 * @key: key to add - cannot be an empty string.
 * @value: value associated with key.
 *
 * Return: Upon failure - 0, Otherwise - 1.
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx = 0;
	hash_node_t *new = NULL;
	hash_node_t *temp = NULL;

	if (ht == NULL || key == NULL || value == NULL)
		return (0);
	if (strlen(key) == 0)
		return (0);
	idx = key_index((const unsigned char *) key, ht->size);

	new = (hash_node_t *) malloc(sizeof(hash_node_t));
	if (new == NULL)
		return (0);
	new->key = (char *) strdup(key);
	new->value = (char *) strdup(value);
	new->next = NULL;
	if ((ht->array)[idx] == NULL)
	{
		(ht->array)[idx] = new;
		return (1);
	}
	else
	{
		temp = (ht->array)[idx];
		while (temp)
		{
			if (strcmp(temp->key, key) == 0)
			{
				free(temp->value);
				temp->value = (char *) strdup(value);
				free(new->key);
				free(new->value);
				free(new);
				return (1);
			}
			temp = temp->next;
		}
		temp = (ht->array)[idx];
		new->next = temp;
		(ht->array)[idx] = new;
		return (1);
	}
}
