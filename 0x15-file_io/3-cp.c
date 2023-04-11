#include <stdio.h>
#include "main.h"
#include <stdlib.h>

/**
 * check_error - checks if files can be opened
 * @file_from: first file
 * @file_to: second file
 * @argv: arguments vector
 *
 * Return: nothing
 */

void check_error(int file_from, int file_to,(...) *argv[])
{
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read to file %s\n", argv[2]);
		exit(99);
	}
}

/**
 * main - copies content from one file to another
 * @argc: number of arguments
 * @argv: arguments vector
 * check_error - checks for error if file doesn't open
 *
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	int file_from, file_to;
	int error_close;
	ssize_t fr, fw;
	char buff[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}

	file_from = open(argv[1], O_RDONLY);

	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	check_error(file_from, file_to, argv);

	fr = 1024;
	while (fr == 1024)
	{
		fr = read(file_from, buff, 1024);
		if (fr == -1)
			check_error(-1, 0, argv);
		fw = write(file_to, buff, fr);
		if (fw == -1)
			check_error(0, -1, argv);
	}
	error_close = close(file_from);
	if (error_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}
	error_close = close(file_to);
	if (error_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}
	return (0);
}
