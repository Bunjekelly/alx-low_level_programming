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
	int o;
	int w;


	if (filename == NULL)
		return (-1);

	o = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (o == -1)
		return (-1);

	if (text_content == NULL)
	{
		w = write(o, text_content, strlen(text_content));

		if (w == -1)
		{
			close(o);
			return (-1);
		}
	}

	close(o);

	return (1);
}
