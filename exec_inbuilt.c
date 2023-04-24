#include "main.h"
/**
 * exec_builtin - executes a builtin command via a syscall
 * @tok: user input
 *
 * Description: execute function associated with user command
 * Return: void
 */
void exec_builtin(char **tok)
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
			(*inbuilt[i].func)(tok);
		}
	}
}
/**
 * our_exit - wrapper to exit syscall
 * @tok: unused user command for typedef compliance
 *
 * Description: exits current process
 * Return: void
 */
void our_exit(__attribute__((unused))char **tok)
{
	exit(EXIT_SUCCESS);
}
/**
 * print_env - print environment variables
 * @tok: unused variable holding user input
 *
 * Description: print environment variables
 * Return: void
 */
void print_env(char **tok)
{
	int i = 0;

	while (tok[i])
	{
		write(1, tok[i], 1024);
		i++;
	}
}
