#include "main.h"

int main(__attribute__((unused))int argc, char *argv[], char *envp[])
{
	/*int retval = 0, pid, status, int_mode = 1;
	size_t bytes = 120; can later assign value if getline does not work properly
	char **tokens, *filename = NULL;
	char *delim = " ";
*/
	while(1)
	{
		char *cmd = NULL;
		int retval = 0, pid, status, int_mode = 1;
		size_t bytes = 120;
		char **tokens, *filename = NULL;
		char *delim = " ";

		int_mode = isatty(STDIN_FILENO);
		if (int_mode)
			get_prompt();
		retval = getline(&cmd, &bytes, stdin);
			/*		retval = our_getline(&cmd, &bytes, STDIN_FILENO);*/
		if (retval == -1)
		{
			exit(98);
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
				retval = our_execve(tokens, envp, filename);/*what could cause execve to fail? check*/
			else
			{	
				wait(&status);
			}

		}
		else
		{
			cmd_not_found_error(argv[0], tokens[0]);
		}
	}
	return (0);
}
