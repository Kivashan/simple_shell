#include "main.h"

void free_str(char *buffer, char *filename, char *getline_cp);

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

	while (1)
	{
		char *buffer = NULL, *delim = " ", *getline_cp, **tokens = NULL, *filename;
		int mode = 0, args = 0, retval = 0, retvalb = 0;
		int a = 0;

		mode = isatty(STDIN_FILENO);
		if (mode)
		{
			retval = get_prompt();
			a = 1;
		}
		retval = getline(&buffer, &bytes, stdin);
		if (retval == -1)
		{
			write(1, "\n", a);
			getline_error_handler(buffer);
		}
		buffer[_strlen(buffer) - 1] = '\0';
		getline_cp = _strdup(buffer);
		args = no_of_args(buffer, delim);
		tokens = word_split(getline_cp, delim);
		filename = _strdup(tokens[0]);
		retvalb = exec_builtin(tokens, env);
		if (retvalb == -1)
		{
			_fork(tokens, env, argv, filename);
		}
		free_str(buffer, filename, getline_cp);
		free_grid(tokens, args);
	}
	return (0);
}

/**
 * free_str - frees all dynamically allocated memory in shell_clone.c
 * @buffer: strinh to free
 * @filename: string to free
 * @getline_cp: string to free
 *
 * Return: Void
 */

void free_str(char *buffer, char *filename, char *getline_cp)
{

	free(buffer);
	free(filename);
	free(getline_cp);

}
