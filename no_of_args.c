#include "main.h"

int no_of_args(char *str, char *delim)
{
	char *tmp = NULL, *new = NULL;
	int args = 0;

	if (!str)
		return (-1);

	tmp = _strdup(str);

	new = strtok(tmp, delim);
	args++;
	while (new != NULL)
	{
		new = strtok(NULL, delim);
		args++;
	}
	free(tmp);
	free(new);

	return (args);
}
