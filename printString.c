#include "main.h"

/**
 * printString - Appends a string to a buffer.
 *
 * @str: The string to append.
 * @buffer: The buffer to append the string to.
 * @count: A pointer to the current position in the buffer.
 */
void printString(const char *str, char *buffer, int *count)
{
	if (str == NULL)
	{
		str = "(null)";
	}
	while (*str != '\0')
	{
		buffer[(*count)++] = *str;
		str++;
		if (*count == PRINTF_BUFFER_SIZE)
		{
			flush_buffer(buffer, count);
		}
	}
}
