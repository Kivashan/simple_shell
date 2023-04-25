#include "main.h"

/**
 * main - shell program starts here
 * @argc: unused count of arguments to main
 * @argv: array of pointers to strings(args to main)
 * @envp: array of pointers to strings(environment variables list)
 *
 * Description: Reads commands from terminal and interpretes for system
 * Return: 0 success!
 */
int main(int argc, char *argv[], char *envp[])
{
	while (1)
	{
		char *cmd = NULL, *delim = " ";
		int retval = 0, pid, status, int_mode = 1;
		size_t bytes = 120;
		char **tokens, *filename = NULL;

		int_mode = isatty(STDIN_FILENO);
		if (int_mode)
			get_prompt();
		retval = getline(&cmd, &bytes, stdin);
		if (retval == -1)
		{
			_puts("\n");
			exit(0);
		}
		cmd[stringlen(cmd) - 1] = '\0';
		tokens = the_tokeniser(cmd, delim);
		if (file_check(tokens, envp, &filename) == 0)
		{
			pid = fork();
			if (pid == -1)
			{
				perror("Error:");
				return (1);
			}
			else if (pid == 0)
				retval = our_execve(tokens, envp, filename);
			else
				wait(&status);
		}
/*		else if (file_check(tokens, envp, &filename) != 0)
			exec_builtin(envp);*/
		else
			cmd_not_found_error(argv[argc - 1], tokens[0]);
	}
	return (0);
}
