#include "main.h"
#include "stdarg.h"
#include "stdio.h"
/**
 * _printf - a function that behaves like printf
 * @format: format string
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	int i;


	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			putchar(format[i]);
			count++;
			continue;
		}

		i++;

		switch (format[i])
		{
			case 'd':
			case 'i':
				printf("%d", va_arg(args, int));
				count++;
				break;
			default:
				putchar('%');
				putchar(format[i]);
				count += 2;
				break;
		}
	}

	va_end(args);

	return (count);
}
