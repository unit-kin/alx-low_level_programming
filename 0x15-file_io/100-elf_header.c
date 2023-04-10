#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void validate_elf_header(unsigned char *header);
void print_magic_numbers(unsigned char *header);
void print_class(unsigned char *header);
void print_data_encoding(unsigned char *header);
void print_elf_version(unsigned char *header);
void print_os_abi(unsigned char *header);
void print_abi_version(unsigned char *header);
void print_elf_type(unsigned int type, unsigned char *header);
void print_entry_point(unsigned long int entry, unsigned char *header);
void close_file(int fd);

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <ELF file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    unsigned char header[EI_NIDENT];
    ssize_t bytes_read = read(fd, header, EI_NIDENT);
    if (bytes_read != EI_NIDENT) {
        fprintf(stderr, "Error: Could not read ELF header\n");
        close_file(fd);
        return EXIT_FAILURE;
    }

    validate_elf_header(header);
    print_magic_numbers(header);
    print_class(header);
    print_data_encoding(header);
    print_elf_version(header);
    print_os_abi(header);
    print_abi_version(header);

    Elf32_Ehdr elf32_header;
    Elf64_Ehdr elf64_header;
    unsigned int elf_class = header[EI_CLASS];

    switch (elf_class) {
        case ELFCLASS32:
            bytes_read = pread(fd, &elf32_header, sizeof(elf32_header), 0);
            if (bytes_read != sizeof(elf32_header)) {
                fprintf(stderr, "Error: Could not read ELF32 header\n");
                close_file(fd);
                return EXIT_FAILURE;
            }
            print_elf_type(elf32_header.e_type, header);
            print_entry_point(elf32_header.e_entry, header);
            break;
        case ELFCLASS64:
            bytes_read = pread(fd, &elf64_header, sizeof(elf64_header), 0);
            if (bytes_read != sizeof(elf64_header)) {
                fprintf(stderr, "Error: Could not read ELF64 header\n");
                close_file(fd);
                return EXIT_FAILURE;
            }
            print_elf_type(elf64_header.e_type, header);
            print_entry_point(elf64_header.e_entry, header);
            break;
        default:
            fprintf(stderr, "Error: Unknown ELF class %d\n", elf_class);
            close_file(fd);
            return EXIT_FAILURE;
    }

    close_file(fd);
    return EXIT_SUCCESS;
}

void validate_elf_header(unsigned char *header)
{
    if (header[0] != 0x7f || header[1] != 'E' || header[2] != 'L' || header[3] != 'F') {
        fprintf(stderr, "Error: Not an ELF file\n");
        exit(EXIT_FAILURE);
    }
}

void print_magic_numbers(unsigned char *header)
{
    printf(" 

