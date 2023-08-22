#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>

/**
 * _printf - Custom printf function to format and print data.
 *
 * @format: The format string containing format specifiers.
 * @...: The arguments to be formatted and printed.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char buffer[PRINTF_BUFFER_SIZE];
	int buffer_count = 0;
	int i, a;
	char x;
	char *p;
	
	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
			{
				x = va_arg(args, int);
				buffer[buffer_count++] = x;
				i++;
				count++;
			}
			else if (format[i + 1] == 's')
			{
                char *p = va_arg(args, char*);
                printString(p, buffer, &buffer_count);
                count++;
                if (buffer_count == PRINTF_BUFFER_SIZE)
                    flush_buffer(buffer, &buffer_count);
                i++;
            }
            else if (format[i + 1] == 'd' || format[i + 1] == 'i')
            {
                int q = va_arg(args, int);
                print_number(q, buffer, &buffer_count);
                count++;
                if (buffer_count == PRINTF_BUFFER_SIZE)
                    flush_buffer(buffer, &buffer_count);
                i++;
            }
            else if (format[i + 1] == 'b')
            {
                unsigned int num = va_arg(args, unsigned int);
                printBinary(num, buffer, &buffer_count);
                count++;
                if (buffer_count == PRINTF_BUFFER_SIZE)
                    flush_buffer(buffer, &buffer_count);
                i++;
            }
            else if (format[i + 1] == 'u')
            {
                unsigned int num = va_arg(args, unsigned int);
                printUnsigned(num, buffer, &buffer_count);
                count++;
                if (buffer_count == PRINTF_BUFFER_SIZE)
                    flush_buffer(buffer, &buffer_count);
                i++;
            }
            else if (format[i + 1] == 'o')
            {
                unsigned int num = va_arg(args, unsigned int);
                printOctal(num, buffer, &buffer_count);
                count++;
                if (buffer_count == PRINTF_BUFFER_SIZE)
                    flush_buffer(buffer, &buffer_count);
                i++;
            }
            else if (format[i + 1] == 'x' || format[i + 1] == 'X')
            {
               unsigned int num = va_arg(args, unsigned int);
                int uppercase = (format[i + 1] == 'X');
                printHexadecimal(num, buffer, &buffer_count, uppercase);
                count++;
                if (buffer_count == PRINTF_BUFFER_SIZE)
                    flush_buffer(buffer, &buffer_count);
                i++;
            }
            else if (format[i + 1] == 'S')
            {
                p = va_arg(args, char*);
                if (p == NULL)
                    p = "(null)";

                for (a = 0; p[a] != '\0'; a++)
                {
                    if (p[a] < 32 || p[a] >= 127)
                    {
                        buffer[buffer_count++] = '\\';
                        buffer[buffer_count++] = 'x';
                        buffer[buffer_count++] = (p[a] >> 4) < 10 ? (p[a] >> 4) + '0' : (p[a] >> 4) - 10 + 'A';
                        buffer[buffer_count++] = (p[a] & 0x0F) < 10 ? (p[a] & 0x0F) + '0' : (p[a] & 0x0F) - 10 + 'A';
                        count += 4;
                    }
                    else
                    {
                        buffer[buffer_count++] = p[a];
                        count++;
                    }

                    if (buffer_count == PRINTF_BUFFER_SIZE)
                        flush_buffer(buffer, &buffer_count);
                }
                i++;
            }
            else if (format[i + 1] == 'p')
            {
                void *ptr = va_arg(args, void*);
                printPointer(ptr, buffer, &buffer_count);
                count++;
                if (buffer_count == PRINTF_BUFFER_SIZE)
                    flush_buffer(buffer, &buffer_count);
                i++;
            }
            else if (format[i + 1] == '%')
            {
                buffer[buffer_count++] = '%';
                count++;
                if (buffer_count == PRINTF_BUFFER_SIZE)
                    flush_buffer(buffer, &buffer_count);
                i++;
            }
            else
            {
                buffer[buffer_count++] = format[i + 1];
                count++;
                if (buffer_count == PRINTF_BUFFER_SIZE)
                    flush_buffer(buffer, &buffer_count);
                i++;
            }
        }
        else
        {
            buffer[buffer_count++] = format[i];
            count++;
            if (buffer_count == PRINTF_BUFFER_SIZE)
                flush_buffer(buffer, &buffer_count);
        }
    }

    if (buffer_count > 0)
        flush_buffer(buffer, &buffer_count);

    va_end(args);

    return count;
}

