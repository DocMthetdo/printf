#include "main.h"
/**
 * printHexadecimal - prints a hexadecimal number
 * @num: number to print
 * @buffer: buffer to print to
 * @count: count of characters printed
 * @uppercase: flag for uppercase printing

*/
void printHexadecimal(unsigned int num, char *buffer, int *count, int uppercase)
{
	char hex[12];
	int hexCount = 0;
	const char *hexDigits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";


	if (num == 0)
	{
		buffer[(*count)++] = '0';
		return;
	}
	while (num > 0)
	{
		hex[hexCount++] = hexDigits[num & 0xF];
		num >>= 4;
	}
	while (hexCount > 0)
	{
		buffer[(*count)++] = hex[--hexCount];
	}
}

/**
 * printUnsigned - prints an unsigned number
 * @num: number to print
 * @buffer: buffer to print to
 * @count: count of characters printed
 */

void printUnsigned(unsigned int num, char *buffer, int *count)
{
	char temp[12];
	int tempCount = 0;


	if (num == 0)
	{
		buffer[(*count)++] = '0';
		return;
	}
	while (num > 0)
	{
		temp[tempCount++] = (num % 10) + '0';
		num /= 10;
	}
	while (tempCount > 0)
	{
		buffer[(*count)++] = temp[--tempCount];
	}
}

/**
 * printOctal - prints an octal number
 * @num: number to print
 * @buffer: buffer to print to
 * @count: count of characters printed
 */

void printOctal(unsigned int num, char *buffer, int *count)
{
	char octal[12];
	int octalCount = 0;


	if (num == 0)
	{
		buffer[(*count)++] = '0';
		return;
	}
	while (num > 0)
	{
		octal[octalCount++] = (num & 7) + '0';
		num >>= 3;
	}
	while (octalCount > 0)
	{
		buffer[(*count)++] = octal[--octalCount];
	}
}
