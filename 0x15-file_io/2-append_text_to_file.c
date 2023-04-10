#include "main.h"

/**
 * append_text_to_file - a function that appends text at the end of a file
 * @filename: the name of the file
 * @text_content: the NULL terminated string to add at the end of the file
 *
 * Return: 1 on success and -1 on failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int fo;
	int fw;
	int len;

	if (filename == NULL)
		return (-1);

	fo = open(filename, O_WRONLY | O_APPEND, 0664);

	if (fo == -1)
		return (-1);
	for (len = 0; text_content[len];)
		len++;

	if (text_content != NULL)

	fw = write(fo, text_content, len);

	if (fw == -1)
		return (-1);


	close(fo);

	return (1);
}
