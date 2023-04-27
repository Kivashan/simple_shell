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
int exec_builtin(char **tok, char **env, char *filename, char *argv[])
{
	int i, retval, pid, status;
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
			retval = (*inbuilt[i].func)(tok, env, argv);
			if (retval == 2)
			{
				pid = fork();
				if (pid == -1)
				{
					perror("Error:");
					exit(98);
				}
				else if (pid == 0)
					_exit(2);
				else
					wait(&status);
			}
			return (retval);
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
int our_exit(char **tok, __attribute__((unused))char **env, char *argv[])
{
	int len = 0, i = 0, sig_fig = 1, num = 0, j = 0;
	
	while (tok[j])
		j++;

	if (tok[1])
	{	
		while (tok[1][i])
		{
			if ((tok[1][i] < '0') || (tok[1][i] > '9'))
			{
				illegal_num_error(tok, argv);
				free_grid(tok, j);
				return (2);
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
	free_grid(tok, j);
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
int print_env(__attribute__((unused))char **tok, char **env,
	__attribute__((unused))char *argv[])

{
	int i = 0, len;

	while (env[i])
	{
		len = _strlen(env[i]);
		write(1, env[i], len);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}

void illegal_num_error (char **tok, char *argv[])
{
	int len = 0;

	len = _strlen(argv[0]);
	write(1, argv[0], len);
	write(1, ": 1: ", 5);
	len = _strlen(tok[0]);
	write(1, tok[0], len);
	write(1, ": Illegal number: ", 18);
	len = _strlen(tok[1]);
	write(1, tok[1], len);
	write(1, "\n", 1);
}
