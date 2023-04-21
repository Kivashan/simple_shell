#include "main.h"

/**
 * no_of_args - returns the number of command line args passed
 * @str: string
 * @delim: delimeter
 *
 * Return: The number of cmd args passed
 */

int no_of_args(char *str, char *delim)
{
	char *tmp = NULL;
	int len = 0, args = 0;

	if (!str)
		return (-1);

	len = stringlen(str);
	tmp = malloc(sizeof(char) * (len + 1));

	if (!tmp)
		return (-1);

	tmp = strtok(str, delim);
	args++;

	while (!tmp)
	{
		tmp = strtok(str, delim);
		args++;
	}
	return (args);
}
