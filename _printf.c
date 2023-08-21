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
				putchar(x);
				i++;
				count++;
			}

			else if (format[i + 1] == 's')
			{
				p = va_arg(args, char*);
				if (p == NULL)
					p = "(null)";
				
				for (a = 0; p[a] != '\0'; a++)
				{
					putchar(p[a]);
					count ++;
				}
				i++;
			}

			else if (format[i + 1] == '%')
			{
				putchar('%');
				i++;
				count++;
			}

			else
			{
				putchar(format[i + 1]);
				count++;
				i++;
			
			}
		}

		else
		{
			putchar(format[i]);
			count++;
		}
	}
	va_end(args);
	return (count);
}
