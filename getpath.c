#include "main.h"
/**
 * getpath - get value of PATH from environment
 * @envr: pointer to array of strings (environment variables)
 *
 * Description: get string of paths to directories with bash commands
 * Return: a string
 */
char *getpath(char **envr)
{
	char *path = "PATH=";
	char *path_str;
	int i, j = 0, k, loc = 0, len = 0;

	for (i = 0; envr[i] != NULL; i++)
	{
		for (j = 0; envr[i][j] == path[j]; j++)
		{
			if (j == 4)
			{
				loc = i;
				break;
			}
		}
			if (j == 4)
				break;
	}
	len = stringlen(envr[loc]) - 4;
	path_str = malloc(sizeof(char) * len);
	for (k = 0; envr[loc][j] != '\0'; k++, j++)
	{
		path_str[k] = envr[loc][j + 1];
	}
	path_str[k] = '\0';
	return (path_str);
}
