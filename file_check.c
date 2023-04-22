#include "main.h"
#include <sys/types.h>
#include <dirent.h>

/**
 * file_check - Checks if file exists in the directories stored under PATH
 * @tokens: an array of pointers to strings storing the cmd args
 * @environ: The environment variable
 *
 * Return: 0 if success, -1 otherwise;
 */

int file_check(char *tokens[], char *environ[])
{
	char *cp1; /* *cp2 *filename;*/
	int /*len = 0, pos = 0, len2 = 0,*/ a = 0;
	cp1 = stringcpy(tokens[0]);

	if (cp1[0] == '/')
	{
		a = access(cp1, F_OK);
		
		if (a == 0)
			return (0);
	}
	else if ((file_finder(tokens, environ)) == 0)
		return (0);
	return (-1);
}
