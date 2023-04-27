#include "main.h"

void free_str(char *buffer, char *getline_cp);

/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 * @env: environment variables
 *
 * Return: 0 is success
 */

int main(__attribute__((unused))int argc, char *argv[], char *env[])
{
	size_t bytes;
	int retvalb = 0;

	while (1)
	{
		char *buffer = NULL, *delim = " ", *getline_cp, **tokens = NULL, *filename;
		int mode = 0, args = 0;
		int a = 0, ret = 0;
		int retval = 0;

		mode = isatty(STDIN_FILENO);
		/*printf("retval1 = %d\n", retval);*/
		if (mode)
		{
			ret = get_prompt();
			a = 1;
		}
		ret = getline(&buffer, &bytes, stdin);
		if (ret == -1)
		{
			write(1, "\n", a);
			/*printf("retval2 = %d\n", retval);*/
			getline_error_handler(buffer, retval);
		}
		buffer[_strlen(buffer) - 1] = '\0';
		getline_cp = _strdup(buffer);
		args = no_of_args(buffer, delim);
		if (args > 1)
		{
			tokens = word_split(getline_cp, delim);
			free_str(buffer, getline_cp);
			filename = _strdup(tokens[0]);
			retvalb = exec_builtin(tokens, env, filename, argv);
			/*if (retvalb == 2)
				return (2);*/
			if (retvalb == -1)
			{
				retval = _fork(tokens, env, argv, filename);
			
				free(filename);
				free_grid(tokens, args);
				if (retval == 127)
					 exit(retval);
			}
		}
		else
			free_str(buffer, getline_cp);
	}
	return (retvalb);
}

/**
 * free_str - frees all dynamically allocated memory in shell_clone.c
 * @buffer: strinh to free
 * @getline_cp: string to free
 *
 * Return: Void
 */

void free_str(char *buffer, char *getline_cp)
{

	free(buffer);
	free(getline_cp);

}
