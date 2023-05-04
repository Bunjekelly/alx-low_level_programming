#include "main.h"

/**
 * get_bit - a function that returns the value of a bit at a given index
 * @index: the index, starting from 0 of the bit you want to get
 * @n: unsigned long int
 *
 * Return: the value of the bit at index index or -1 if error
 */

int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= 64)
		return (-1);
	if ((n & (1 << index)) == 0)
		return (0);
	return (1);
}
