#include "main.h"

/**
 * append_text_to_file - This is to append text to the end
 * @filename:This is the name of file
 * @text_content: text to append to file
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, wrlen, textlen = 0;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[textlen])
			textlen++;
		wrlen = write(fd, text_content, textlen);
		if (wrlen != textlen)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}
