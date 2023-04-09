#include <stdlib.h>
#include "main.h"

/**
 * read_textfile - a function that reads a text file and
 * prints it to the POSIX standard output.
 * @letters: number of letters it should read and print
 * @filename: the pointer
 *
 * Return: actual number of letters it could read and print
 * or 0 if file can't be opened, or write fails or filename is NULL
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t fo, r;
	char *buff;


	fo = open(filename, O_RDONLY);

	if (fo == -1)
		return (0);

	buff = malloc(sizeof(char) * letters + 1);
	if (buff == NULL)
		return (0);

	r = read(fo, buff, letters);
	if (r == -1)
		return (0);

	if (write(STDOUT_FILENO, buff, r) != r)
	
		return (0);
	free(buff);

	close(fo);

	return (r);
}
