#include <elf.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

/**
 * main - checks the code
 * @argc: number of arguments
 * @argv: argument vector
 *
 * Return: 0 on success.
 */

int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *h;
	int fo, fr;

	fo = open(argv[1], O_RDONLY);
	if (fo == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	h = malloc(sizeof(Elf64_Ehdr));
	if (h == NULL)
	{
		c_elf(fo);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	fr = read(fo, h, sizeof(Elf64_Ehdr));
	if (fr == -1)
	{
		free(h);
		c_elf(fo);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}
	verify(h->e_ident);
	printf("ELF Header:\n");
	d_magic(h->e_ident);
	d_class(h->e_ident);
	d_data(h->e_ident);
	d_version(h->e_ident);
	d_osabi(h->e_ident);
	d_abi(h->e_ident);
	det_type(h->e_type, h->e_ident);
	det_entry(h->e_entry, h->e_ident);

	free(h);
	c_elf(fo);
	return (0);
}

/**
 * d_magic -displays the magic numbers of an ELF header.
 * @e_ident: pointer to an array containing the ELF magic numbers.
 *
 * Return: nothing
 */

void d_magic(unsigned char *e_ident)
{
	int k;

	printf("  Magic:   ");

	for (k = 0; k < EI_NIDENT; k++)
	{
		printf("%02x", e_ident[k]);

		if (k == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * d_version - displays the version of an ELF header.
 * @e_ident: pointer to an array containing the ELF version.
 */

void d_version(unsigned char *e_ident)
{
	printf("  Version:                           %d",
		   e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * d_osabi - displays the OS/ABI of an ELF header.
 * @e_ident: pointer to an array containing the ELF version.
 */

void d_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");

	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * d_abi - dislays the ABI version of an ELF header.
 * @e_ident: pointer to an array containing the ELF ABI version.
 */

void d_abi(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
		   e_ident[EI_ABIVERSION]);
}

/**
 * det_type - displays the type of an ELF header.
 * @e_type: ELF type.
 * @e_ident: pointer to an array containing the ELF class.
 */

void det_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");

	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
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
	default:
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * d_data - displays the data of an ELF header.
 * @e_ident: pointer to an array containing the ELF class.
 */

void d_data(unsigned char *e_ident)
{
	printf("  Data:                              ");

	switch (e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * d_class - displays the class of an ELF header.
 * @e_ident: pointer to an array containing the ELF class.
 */

void d_class(unsigned char *e_ident)
{
	printf("  Class:                             ");

	switch (e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * det_entry - displays the entry point of an ELF header.
 * @e_entry: address of the ELF entry point.
 * @e_ident: pointer to an array containing the ELF class.
 */

void det_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:               ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
				  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * verify - verifies if a file is an ELF file.
 * @e_ident: pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file - exit code 98.
 */

void verify(unsigned char *e_ident)
{
	int k;

	for (k = 0; k < 4; k++)
	{
		if (e_ident[k] != 127 &&
			e_ident[k] != 'E' &&
			e_ident[k] != 'L' &&
			e_ident[k] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * c_elf - closes an ELF file.
 * @elf: the ELF file.
 *
 * Description: If the file cannot be closed - exit code 98.
 */

void c_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't close fd %d\n", elf);

		exit(98);
	}
}


