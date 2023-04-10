#include "main.h"

/**
 * create_file - creates a file and writes a text to it
 * @filename: This is the name of the file to be created
 * @text_content: This is a NULL terminated string to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd, ret_val, len = 0;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[len] != '\0')
			len++;

		ret_val = write(fd, text_content, len);
		if (ret_val == -1 || ret_val != len)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}
