#include "main.h"

/**
 * main - Entry point.
 * @argc: Argument count.
 * @argv: Array of argument strings.
 *
 * Return: 0 on success, 98 on failure.
 */
int main(int argc, char **argv)
{
	int fd, i;
	unsigned char e_ident[EI_NIDENT];

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s <ELF_FILE>\n", argv[0]);
		return (EXIT_FAILURE);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Cannot read %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	if (read(fd, e_ident, EI_NIDENT) != EI_NIDENT)
	{
		dprintf(STDERR_FILENO, "Error: Cannot read %s\n", argv[1]);
		close(fd);
		return (EXIT_FAILURE);
	}

	check_elf(e_ident);
	print_magic(e_ident);
	print_class(e_ident);
	print_data(e_ident);
	print_version(e_ident);
	print_osabi(e_ident);
	print_abi(e_ident);

	if (lseek(fd, 16, SEEK_SET) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Cannot read %s\n", argv[1]);
		close(fd);
		return (EXIT_FAILURE);
	}

	if (read(fd, &i, 4) != 4)
	{
		dprintf(STDERR_FILENO, "Error: Cannot read %s\n", argv[1]);
		close(fd);
		return (EXIT_FAILURE);
	}

	print_type(i, e_ident);

	if (lseek(fd, 24, SEEK_SET) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Cannot read %s\n", argv[1]);
		close(fd);
		return (EXIT_FAILURE);
	}

	if (read(fd, &i, 8) != 8)
	{
		dprintf(STDERR_FILENO, "Error: Cannot read %s\n", argv[1]);
		close(fd);
		return (EXIT_FAILURE);
	}

	print_entry(i, e_ident);

	close_elf(fd);

	return (EXIT_SUCCESS);
}

/**
 * check_elf - Checks if a file is an ELF file.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file - exit code 98.
 */
void check_elf(unsigned char *e_ident)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (e_ident[index] != 127 &&
				e_ident[index] != 'E' &&
				e_ident[index] != 'L' &&
				e_ident[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(EXIT_FAILURE);
		}
	}
}

/**
 * print_magic - Prints the magic numbers of an ELF header.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Magic numbers are separated by spaces.
 */
void print_magic(unsigned char *e_ident)
{
	int index;

	printf("ELF Header:\n");
	printf("  Magic:   ");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", e_ident[index]);

		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_class - Prints the class of an ELF

