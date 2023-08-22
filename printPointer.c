#include "main.h"

/**
 * printPointer - Formats a pointer and stores it in a buffer.
 *
 * @ptr: The pointer to format and print.
 * @buffer: The buffer to store the formatted pointer.
 * @count: A pointer to the current position in the buffer.
 */
void printPointer(void *ptr, char *buffer, int *count)
{
	int printed = snprintf(buffer + (*count), PRINTF_BUFFER_SIZE - (*count), "%p", ptr);
	
	if (printed >= 0 && printed < PRINTF_BUFFER_SIZE - (*count))
	{
		(*count) += printed;
	}
	else
	{
		fprintf(stderr, "Error: Buffer overflow in printPointer\n");
	}
}
