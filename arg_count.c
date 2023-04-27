#include "main.h"

/**
 * arg_count - count the number of times that commands passed in the shell
 *
 * Return: The number of times commands are inputed in the shell
 */

int arg_count(void)
{
	static int count = 1;
	count++;

	return (count);
}
