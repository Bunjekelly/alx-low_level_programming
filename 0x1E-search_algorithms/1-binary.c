#include "search_algos.h"
#include <stdio.h>
#include <stddef.h>

/**
 * binary_search - a function that searches for a value in a sorted array of
 * integers using the Binary search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: the number of elements in array
 * @value:  the value to search for
 *
 * Return: the index where value is located or -1
 */

int binary_search(int *array, size_t size, int value)
{
	size_t left, right, mid, i;

	left = 0;
	right = size - 1;

	if (array == NULL)
		return (-1);
	while (left <= right)
	{
		mid = (left + right) / 2;

		printf("Searching in array: ");
		for (i = left; i < right; i++)
			printf("%d, ", array[i]);
		printf("%d\n", array[i]);
		if (array[mid] == value)
			return (mid);
		else if (array[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (-1);
}
