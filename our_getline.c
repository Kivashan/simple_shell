#include "main.h"

ssize_t our_getline(char **lineptr, size_t *n,
		int stream)
{
	ssize_t bytes_read;
	char *buffer;

	buffer = malloc(sizeof(char) * (*n));
	if (!buffer)
		return (-2);
	bytes_read = read(stream, buffer, *n);
	buffer[bytes_read - 1] = '\0';
	*lineptr = stringcpy(buffer);

	free(buffer);
	return (bytes_read);
}
