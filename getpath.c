#include "main.h"

char *getpath(char **envr)
{
	char *path = "PATH=";
	char *return_path;
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
	return_path = malloc(sizeof(char) * len);
	for (k = 0; envr[loc][j] != '\0'; k++, j++)
	{
		return_path[k] = envr[loc][j + 1];
	}
	return_path[k] = '\0';
	return (return_path);
}
