#include "main.h"
#include <sys/types.h>
#include <dirent.h>

int file_check(char *tokens[], char *environ[])
{
	char *cp1, *cp2, *filename;
	int len = 0, pos = 0, len2 = 0;
	DIR *fd;
	struct dirent *entry;

	cp1 = stringcpy(tokens[0]);
	cp2 = stringcpy(tokens[0]);
	len = stringlen(cp2) - 1;

	if (cp1[0] == '/')
	{
		for (;cp2[len] != '/'; len--, len2++)
			cp2[len] = '\0';

		filename = malloc(sizeof(char) * (len2));
		if (!filename)
		{
			free_fc(filename, cp1, cp2);
			return (-1);
		}
		get_filename(cp1, filename, ++len, &pos);
                filename[pos] = '\0';
		fd = opendir(cp2);
		if (fd == NULL)
		{
			free_fc(filename, cp1, cp2);
			return (-1);
		}
		while ((entry = readdir(fd)) != NULL)
		{
			if ((strcmp(entry->d_name, filename)) == 0)
			{
				free_fc(filename, cp1, cp2);
				return (0);
			}
		}
		closedir(fd);
	}
	else if ((file_finder(tokens, environ)) == 0)
		return (0);
	return (-1);
}