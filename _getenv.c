#include "main.h"

char *_getenv(char *var)
{
	char *path;
	extern char **environ;
	int i = 0, j = 0, k = 0, loc = 0, len = 0;

	while (environ[i])
	{
		j = 0;
		while (var[j] == environ[i][j])
		{
			if (j == 3)
			{
				loc = i;
				break;
			}
			j++;
		}
		if (j == 3)
			break;
		i++;
	}
	len = _strlen(environ[loc]) - 4;
	path = malloc(sizeof(char) * len);
	
	for (k = 0; environ[loc][j + 2] != '\0'; k++)
	{
		path[k] = environ[loc][j + 2];
		j++;
	}
	path[k] = '\0';

	return (path);
}





