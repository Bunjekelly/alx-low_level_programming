#include "main.h"

/**
 * _isalpha - Shows 1 if the input is a
 * letter Another cases, shows 0
 *
 * @c: The character to be checked
 *
 * Return: 1 for letters, 0 otherwise
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
	_putchar('\n');
}
