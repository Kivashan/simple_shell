#include "main.h"
#include <sys/types.h>
#include <dirent.h>

/**
 * file_finder - checks to see if file exists in the paths stored in the PATH
 * @tokens: An array of pointers to strings
 * @environ: Environment variable
 * @filename: A string - full path to command
 *
 * Return: 0 if file exists, -1 otherwise
 */

char **file_finder(char *tokens[], char *environ[], char **filename)
{
	char **path_token = NULL, *delim = ":", *cp1 = NULL, *path = NULL;
	int i = 0;
	DIR *fd;
	struct dirent *entry;

	path = getpath(environ);
	path_token = the_tokeniser(path, delim);
	cp1 = stringcpy(tokens[0]);

	while (path_token[i] != NULL)
	{
		fd = opendir(path_token[i]);
		if (fd == NULL)
		{
		/*	free_ff(path_token, path, cp1);*/
			return (NULL);
		}
		while ((entry = readdir(fd)) != NULL)
		{
			if ((strcmp(entry->d_name, cp1)) == 0)
			{
			/*	free_ff(path_token, path, cp1);*/
				*filename = stringconcat(path_token[i], tokens[0]);
				return (filename);
			}
		}
		closedir(fd);
		i++;
	}
	return (NULL);
}
