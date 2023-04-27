#include "main.h"
/**
 * exec_builtin - executes a builtin command via a syscall
 * @tok: user input
 * @env: environment
 * @filename: full pathname of file/command
 *
 * Description: execute function associated with user command
 * Return: void
 */
int exec_builtin(char **tok, char **env, char *filename)
{
	int i;
	get_func inbuilt[] = {
		{"exit", our_exit},
		{"env", print_env},
		{NULL, NULL}
	};

	for (i = 0; inbuilt[i].cmd != NULL; i++)
	{
		if ((stringcomp(inbuilt[i].cmd, tok[0])) == 0)
		{
			free(filename);
			(*inbuilt[i].func)(tok, env);
			return (0);
		}
	}
	return (-1);
}
/**
 * our_exit - wrapper to exit syscall
 * @tok: unused user command for typedef compliance
 * @env: environment
 *
 * Description: exits current process
 * Return: void
 */
void our_exit(char **tok,
	__attribute__((unused))char **env)
{
	int i = 0;

	while (tok[i])
		i++;

	free_grid(tok, i);

	exit(EXIT_SUCCESS);
}
/**
 * print_env - print environment variables
 * @tok: unused variable holding user input
 * @env: environment
 *
 * Description: print environment variables
 * Return: void
 */
void print_env(__attribute__((unused))char **tok, char **env)
{
	int i = 0, len;

	while (env[i])
	{
		len = _strlen(env[i]);
		write(1, env[i], len);
		write(1, "\n", 1);
		i++;
	}
}
