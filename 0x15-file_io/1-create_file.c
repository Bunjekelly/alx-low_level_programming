#include "main.h"
#include <string.h>

/**
 * create_file - a function that creates a file
 * @filename: name of the file to create
 * @text_content: NULL terminator string to write to the file
 *
 * Return: 1 on success, -1 on failure
 */

int create_file(const char *filename, char *text_content)
{
	int fo;
	int fw;
	int len = 0;


	if (filename == NULL)
		return (-1);

	fo = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (fo == -1)
		return (-1);

	if (text_content == NULL)
		text_content = "";

	for (len = 0; text_content[len]; len++)
		;


	fw = write(fo, text_content, strlen(text_content));

	if (fw == -1)
		return (-1);

	close(fo);

	return (1);
}
