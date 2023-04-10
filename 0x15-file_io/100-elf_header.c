#include "main.h"
/**
 * main - displays the information contained in the ELF header of an ELF file
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char **argv)
{
	int fd, ret_read, i;
	Elf64_Ehdr header;
	char *error;

	if (argc != 2)
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]), exit(98);

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		dprintf(STDERR_FILENO, "Error: Cannot read file %s\n", argv[1]), exit(98);

	ret_read = read(fd, &header, sizeof(header));
	if (ret_read != sizeof(header))
		dprintf(STDERR_FILENO, "Error: Cannot read file %s\n", argv[1]), exit(98);

	/* Check if file is ELF */
	if (header.e_ident[EI_MAG0] != ELFMAG0 ||
			header.e_ident[EI_MAG1] != ELFMAG1 ||
			header.e_ident[EI_MAG2] != ELFMAG2 ||
			header.e_ident[EI_MAG3] != ELFMAG3)
		dprintf(STDERR_FILENO, "%s: Error: Not an ELF file\n", argv[0]), exit(98);

	printf("Magic:   ");
	i = 0;
	do {
		printf("%02x ", header.e_ident[i]);
	} while (++i < EI_NIDENT);
	printf("\n");

	printf("Class:                             ");
	switch (header.e_ident[EI_CLASS])
	{
		case ELFCLASSNONE: error = "none"; break;
		case ELFCLASS32: error = "ELF32"; break;
		case ELFCLASS64: error = "ELF64"; break;
		default: error = "unknown"; break;
	}
	printf("%s\n", error);

	printf("Data:                              ");
	switch (header.e_ident[EI_DATA])
	{
		case ELFDATANONE: error = "none"; break;
		case ELFDATA2LSB: error = "2's complement, little endian"; break;
		case ELFDATA2MSB: error = "2's complement, big endian"; break;
		default: error = "unknown"; break;
	}
	printf("%s\n", error);

	printf("Version:                           %d\n", header.e_ident[EI_VERSION]);

	printf("OS/ABI:                            ");
	switch (header.e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV: error = "UNIX - System V"; break;
		case ELFOSABI_HPUX: error = "UNIX - HP-UX"; break;
		case ELFOSABI_NETBSD: error = "UNIX - NetBSD"; break;
		case ELFOSABI_LINUX: error = "UNIX - Linux"; break;
		case ELFOSABI_SOLARIS: error = "UNIX - Solaris"; break;
		case ELFOSABI_IRIX: error = "UNIX - IRIX"; break;
		case ELFOSABI_FREEBSD: error = "UNIX - FreeBSD"; break;
		case ELFOSABI_TRU64: error = "UNIX - TRU64"; break;
		case ELFOSABI_ARM: error = "ARM"; break;
		case ELFOSABI_STANDALONE: error = "Standalone App"; break;
		default: error = "UNIX - System V"; break;
	}
	printf("%s\n", error);

	printf("ABI Version:                       %d\n", header
