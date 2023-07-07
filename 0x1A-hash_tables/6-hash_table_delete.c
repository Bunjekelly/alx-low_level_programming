#include "hash_tables.h"
#include <stdlib.h>

/**
 * hash_table_delete - deletes a hash table
 * @ht: pointer to the hash table
 *
 * Return: nothing
 */

void hash_table_delete(hash_table_t *ht)
{
	unsigned long int k;
	hash_node_t *temp1, *temp2;

	if (ht == NULL)
		return;

	for (k = 0; k < ht->size; k++)
	{
		temp1 = ht->array[k];
		while ((temp1 = temp2) != NULL)
		{
			temp1 = temp1->next;
			free(temp2->key);
			free(temp2->value);
			free(temp2);
		}
	}
	free(ht->array);
	free(ht);
}
