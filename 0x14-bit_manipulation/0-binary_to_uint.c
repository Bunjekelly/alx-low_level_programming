#include "main.h"
#include <stddef.h>

/**
 * binary_to_uint - a function that converts a binary to unsigned int
 * @b: pointer to a string of 0 and 1 chars
 *
 * Return: the converted number or 0
 */

unsigned int binary_to_uint(const char *b)
{
	int k;
	unsigned int j = 0;

	if (b == NULL)
		return (0);
	for (k = 0; b[k]; k++)
	{
		if (b[k] != '0' && b[k] != '1')
			return (0);
		j = 2 * j + (b[k] - '0');
	}
	return (j);
}
