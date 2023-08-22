#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define PRINTF_BUFFER_SIZE 1024


int _printf(const char *format, ...);
void print_number(int n, char *buffer, int *count);
void flush_buffer(char *buffer, int *count);
void printBinary(unsigned int num, char *buffer, int *count);
void printPointer(void *ptr, char *buffer, int *count);
void printHexadecimal(unsigned int num, char *buffer, int *count, int uppercase);
void printUnsigned(unsigned int num, char *buffer, int *count);
void printOctal(unsigned int num, char *buffer, int *count);
void printString(const char *str, char *buffer, int *count);

#endif
