#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <elf.h>
#include "main.h"

int main(int argc, char *argv[]) {
    // Check that the program was called with an argument
    if (argc != 2) {
        fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        exit(98);
    }

    // Open the file for reading
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Error: could not open file %s\n", argv[1]);
        exit(98);
    }

    // Read the ELF header into a buffer
    Elf64_Ehdr header;
    if (read(fd, &header, sizeof(header)) != sizeof(header)) {
        fprintf(stderr, "Error: could not read ELF header\n");
        exit(98);
    }

    // Check that the file is an ELF file
    if (memcmp(header.e_ident, ELFMAG, SELFMAG) != 0) {
        fprintf(stderr, "Error: file %s is not an ELF file\n", argv[1]);
        exit(98);
    }

    // Display the required information from the header
    printf("Magic: ");
    for (int i = 0; i < EI_NIDENT; i++) {
        printf("%02x ", header.e_ident[i]);
    }
    printf("\n");

    printf("Class: %s\n", header.e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");

    printf("Data: %s\n", header.e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");

    printf("Version: %d\n", header.e_ident[EI_VERSION]);

    printf("OS/ABI: ");
    switch (header.e_ident[EI_OSABI]) {
        case ELFOSABI_SYSV:
            printf("UNIX - System V\n");
            break;
        case ELFOSABI_HPUX:
            printf("HP-UX\n");
            break;
        case ELFOSABI_NETBSD:
            printf("NetBSD\n");
            break;
        case ELFOSABI_LINUX:
            printf("Linux\n");
            break;
        case ELFOSABI_SOLARIS:
            printf("Solaris\n");
            break;
        case ELFOSABI_AIX:
            printf("AIX\n");
            break;
        case ELFOSABI_IRIX:
            printf("IRIX\n");
            break;
        case ELFOSABI_FREEBSD:
            printf("FreeBSD\n");
            break;
        case ELFOSABI_OPENBSD:
            printf("OpenBSD\n");
            break;
        default:
            printf("<unknown: %d>\n", header.e_ident[EI_OSABI]);
            break;
    }

    printf("ABI Version: %d\n", header.e_ident[EI_ABIVERSION]);

    printf("Type: ");
    switch (header.e_type) {
        case ET_NONE:
            printf("NONE (No file type)\n");
            break;
        case ET_REL:
            printf("REL (Relocatable file)\n");
            break;
        case ET_EXEC:
            printf("EXEC (Executable file)\n");
            break;
        case ET_DYN:
            printf("DYN (Shared object file)\n");
            break;
        case ET_CORE:
            printf("CORE (Core file)\n");
            break;
       

