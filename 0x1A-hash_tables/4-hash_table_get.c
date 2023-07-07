#include "hash_tables.h"
#include <string.h>
#include <stdlib.h>

/**
 * hash_table_get - retrieves the value associated with the key
 * @ht: pointer to  hash table
 * @key: key of the element
 *
 * Return: value assocaaited with key or NULL
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *temp;
	unsigned long int idx;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	idx = key_index((const unsigned char *)key, ht->size);
	temp = ht->array[idx];
	while (temp != NULL)
	{
		if (strcmp(temp->key, key) == 0)
			return (temp->value);
		temp = temp->next;
	}
	return (NULL);
}
