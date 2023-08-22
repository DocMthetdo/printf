#include "main.h"

/**
 * flush_buffer - Writes contents of a buffer to standard output
 *
 * @buffer: The buffer containing the data to be written.
 * @count: A pointer to the current count of data in the buffer.
 */
void flush_buffer(char *buffer, int *count)
{
	write(STDOUT_FILENO, buffer, *count);
	*count = 0;
}
