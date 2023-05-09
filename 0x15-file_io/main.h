#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int _putchar(char c);
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
void verify(unsigned char *e_ident);
void d_magic(unsigned char *e_ident);
void d_class(unsigned char *e_ident);
void d_data(unsigned char *e_ident);
void d_version(unsigned char *e_ident);
void d_abi(unsigned char *e_ident);
void d_osabi(unsigned char *e_ident);
void det_type(unsigned int e_type, unsigned char *e_ident);
void det_entry(unsigned long int e_entry, unsigned char *e_ident);
void c_elf(int elf);

#endif
