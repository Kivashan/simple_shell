#include "main.h"

int file_check(char *tokens[])
{
	char **path = NULL, *tmp;
	struct stat st;
	int i = 0, size = 0;

	if (tokens[0][0] == '/')
	{
		if (stat(tokens[0], &st) == 0)
			return (0);
		else
			return (-1);
	}

	path = abs_path(tokens);
	while (path[size] != NULL)
		size++;

	while (path[i])
	{
		if (stat(path[i], &st) == 0)
		{
			tmp = tokens[0];
			tokens[0] = _strdup(path[i]);
			free(tmp);
			free_grid(path, size);
			return (0);
		}
		i++;
	}
	
	free_grid(path, size);

	return (-1);
}
