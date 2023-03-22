#include "function_pointers.h"

/**
 * print-name - prints a name
 * @name: input name
 * @f: function pointer
 *
 * Return: nothing
 */

void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;
	f(name);
}
