#include "main.h"
/**
 * getline_error_handler - handle errors from getline & handle EOF
 * @buffer: user input
 *
 * Return: void
 */
void getline_error_handler(char *buffer)
{
	free(buffer);
	exit(0);
}
