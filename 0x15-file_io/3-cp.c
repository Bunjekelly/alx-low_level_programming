#include <stdio.h>
#include "main.h"
#include <stdlib.h>

/**
 * copy_file - a function that copies content from one file
 * int another
 * @file_from: first file
 * @file_to: second file
 *
 * Return: nothing
 */
void copy_file(char *file_from, char *file_to)
{
	int f1, f2;
	ssize_t fr, fw;
	char buff[1024];

	f1 = open(file_from, O_RDONLY);
	if (f1 == -1)
	{
		dprintf(2, "Error: can't read from file %s\n", file_from);
		exit(98);
	}
	f2 = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (f2 == -1)
	{
		dprintf(2, "Error: can't write into file %s\n", file_to);
		exit(99);
	}
	fr = read(f1, buff, 1024);
	while (fr > 0)
	{
		fw = write(f2, buff, fr);
		if (fw == -1)
		{
			dprintf(2, "Error: can't write into %s\n", file_to);
			exit(99);
		}
	}
	if (fr == -1)
	{
		dprintf(2, "Error: can't read file from %s\n", file_from);
		exit(98);
	}
	if (close(f1) == -1)
	{
		dprintf(2, "Error: can't close fd %d\n", f1);
		exit(100);
	}
	if (close(f2) == -1)
	{
		dprintf(2, "Error: can't close fd %d\n", f2);
		exit(100);
	}
}


/**
 * main - checks the code
 * @argc: number of arguments
 * @argv: arguments vector
 * check_error - checks for error if file doesn't open
 *
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		dprintf(2, "Usage: cp file_from file_to\n");
		exit(97);
	}
	copy_file(argv[1], argv[2]);
	return (0);
}
