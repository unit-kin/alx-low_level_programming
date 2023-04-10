#include "main.h"

/**
 * read_textfile - This basically reads a txt file and prints it to the POSIX standard output
 * @filename: This is the name of the file to read
 * @letters:This is the number of letters to read and print
 *
 * Return: the actual number of letters read and printed, or 0 in the case of a failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd, num_read;
	char *buf;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
		return (0);

	num_read = read(fd, buf, letters);
	if (num_read == -1)
	{
		free(buf);
		close(fd);
		return (0);
	}

	num_read = write(STDOUT_FILENO, buf, num_read);
	if (num_read == -1 || (size_t) num_read != letters)
	{
		free(buf);
		close(fd);
		return (0);
	}

	free(buf);
	close(fd);

	return (num_read);
}
