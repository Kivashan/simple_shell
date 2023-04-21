#include "main.h"

int main()/*int argc, char *argv[], char *envp[]*/
{
	char *cmd = NULL;
	int retval, /*retvale = 0, pid, status, */int_mode = 1;/* i = 0;*/
	size_t bytes;/* can later assign value if getline does not work properly */
/*	char **tokens;
	char *delim = " ";
	extern char **environ;
	char *tmp;*/

	while(1)
	{
		int_mode = isatty(STDIN_FILENO);
		if (int_mode)
			get_prompt();
			/*cmd = malloc(sizeof(char) * bytes);
			if (!cmd)
				return (-1);*/
		retval = getline(&cmd, &bytes, stdin);
			/*		retval = our_getline(&cmd, &bytes, STDIN_FILENO);*/
		if (retval == -1)
		{
			free(cmd);
			exit(98);
		}
		cmd[stringlen(cmd) - 1] = '\0';
/*			tokens = the_tokeniser(cmd, delim);
			if (file_check(tokens, environ) == 0)
			{
				pid = fork();
				if (pid == -1)
				{
					perror("Error:");
					return (1);
				}
				else if (pid == 0)
					retvale = our_execve(tokens, environ);
				else
					wait(&status);
			}
			else
				cmd_not_found_error(argv[0], tokens[0]); error message to match linux */
	}
	free(cmd);	
	return (0);
}
