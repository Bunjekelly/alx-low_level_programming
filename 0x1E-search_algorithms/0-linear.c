#include "search_algos.h"
#include <stdio.h>
#include <stddef.h>

/**
 * linear_search - a function that searches for a value in an array of integers
 * using the Linear search algorithm
 * @array: pointer to first element
 * @size:  number of elements in array
 * @value: the value to search for
 *
 * Return: first index where value is located or -1
 */

int linear_search(int *array, size_t size, int value)
{
	size_t i = 0;

	if (array == NULL)
		return (-1);

	for (i = 0; i < size; i++)
	{
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}
	return (-1);
}
