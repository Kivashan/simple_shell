#include "main.h"
#include <sys/types.h>
#include <dirent.h>

/**
 * file_finder - checks to see if file exists in the paths stored in the PATH
 * variable
 * @tokens: An array of pointers to strings
 * @environ: Environment variable
 *
 * Return: 0 if file exists, -1 otherwise
 */

int file_finder(char *tokens[], char *environ[])
{
	char **path_token, *delim = ":", *cp1;
	int i = 0;
	DIR *fd;
	struct dirent *entry;

	path_token = the_tokeniser(getpath(environ), delim);
	cp1 = stringcpy(tokens[0]);

	while (path_token[i] != NULL)
	{
		fd = opendir(path_token[i]);
		if (fd == NULL)
		{
			free_grid(path_token);
			free(cp1);
			return (-1);
		}
		while ((entry = readdir(fd)) != NULL)
		{
			if ((strcmp(entry->d_name, cp1)) == 0)
			{
				free_grid(path_token);
				free(cp1);
				return (0);
			}
		}
		closedir(fd);
		i++;
	}
	free_grid(path_token);
	free(cp1);
	return (-1);
}
