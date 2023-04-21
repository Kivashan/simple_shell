#include "main.h"
#include <sys/types.h>
#include <dirent.h>

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
