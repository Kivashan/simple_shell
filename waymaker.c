#include "main.h"

char **waymaker(int *num)
{
	char **the_narrows = NULL;
	char *var = "PATH";
	char *path = _getenv(var);
	char *delim = ":";
	int i = 0;

	the_narrows = word_split(path, delim);

	while (the_narrows[i] != NULL)
	{
		*num = *num + 1;
		i++;
	}
	free(path);
	path = NULL;

	return (the_narrows);
}



