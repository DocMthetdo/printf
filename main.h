#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define PRINTF_BUFFER_SIZE 1024


int _printf(const char *format, ...);
void printChar(char c, int *count);
void print_number(int n, int *count);
void flush_buffer(char *buffer, int *count);
void printBinary(unsigned int n, int *count);
void printPointer(void *ptr, char *buffer, int *count);
void printHexadecimal(unsigned int num, char *buffer, int *count, int uppercase);
void print_unsigned(unsigned int n, int *count);
void printOctal(unsigned int num, char *buffer, int *count);
void printStr(const char *str, int *count);

#endif
