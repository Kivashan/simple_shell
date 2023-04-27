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
void our_exit(char **tok, __attribute__((unused))char **env)
{
	int len = 0, i = 0, sig_fig = 1, num = 0;

	if (tok[1])
	{	
		while (tok[1][i])
		{
			if ((tok[1][i] < '0') || (tok[1][i] > '9'))
			{
				write(1, tok[1], 10);
				write(1, " :invalid number", 15);
			}
			i++;
			len++;
			sig_fig *= 10;
		}

		sig_fig /= 10;

		for (i = 0; tok[1][i]; i++)
		{
			num += (tok[1][i] - 48) * sig_fig;
			sig_fig /= 10;
		}
	}
	free_grid(tok, len);
	exit(num);
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
