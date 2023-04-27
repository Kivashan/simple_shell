#include "main.h"

/**
 * arg_count - count the number of times that commands passed in the shell
 * @flag: a flag to determine if count is incremented
 *
 * Return: The number of times commands are inputed in the shell
 */

char arg_count(int flag)
{
	static int count = 1;
	char i = '0';

	i = i + count;
	if (flag == 1)
		count++;
	return (i);
}
