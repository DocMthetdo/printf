#include "main.h"
/**
 * print_number - prints a number
 * @n: number to print
 * @buffer: buffer to print to
 * @count: count of characters printed
 */

void print_number(int n, char *buffer, int *count)
{
	char temp[12];
	int tempCount = 0;


	if (n < 0)
	{
		buffer[(*count)++] = '-';
		n = -n;
	}
	if (n == 0)
	{
		buffer[(*count)++] = '0';
		return;
	}
	while (n > 0)
	{
		temp[tempCount++] = (n % 10) + '0';
		n /= 10;
	}
	while (tempCount > 0)
	{
		buffer[(*count)++] = temp[--tempCount];
	}
}
