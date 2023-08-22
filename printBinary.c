#include "main.h"

/**
 * printBinary - Converts an unsigned integer to binary
 *
 * @num: The unsigned integer to convert to binary.
 * @buffer: The buffer to store the binary representation.
 * @count: A pointer to the current position in the buffer.
 */
void printBinary(unsigned int num, char *buffer, int *count)
{
	if (num == 0)
	{
		buffer[(*count)++] = '0';
		return;
	}
	char binary[32];
	int binaryCount = 0;

	while (num > 0)
	{
		binary[binaryCount++] = (num & 1) ? '1' : '0';
		num >>= 1;
	}
	while (binaryCount > 0)
	{
		buffer[(*count)++] = binary[--binaryCount];
	}
}
