#include "main.h"

/**
 * waymaker - splits the path variable into tokens
 * @num: a pointer to an int, used to track the size of the array of pointers
 * @env: an array of pointers to strings
 *
 * Return: an array of pointers to strings
 */

char **waymaker(int *num, char **env)
{
	char **the_narrows = NULL;
	char *var = "PATH";
	char *path = _getenv(var, env);
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



