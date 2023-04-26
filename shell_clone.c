#include "main.h"

int main(__attribute__((unused))int argc, char *argv[], char *env[])
{
	size_t bytes;

	while (1)
	{
		char *buffer = NULL, *delim = " ", *getline_cp, **tokens = NULL, *filename;
		int mode = 0, args = 0, retval = 0, retvalb = 0, pid, status;

		mode = isatty(STDIN_FILENO);
		if (mode) 
			retval = get_prompt();
		retval = getline(&buffer, &bytes, stdin);
		if (retval == -1) 
			getline_error_handler(buffer);
		buffer[_strlen(buffer) - 1] = '\0';	
		getline_cp = _strdup(buffer);
		args = no_of_args(buffer, delim);
		tokens = word_split(getline_cp, delim);
		filename = _strdup(tokens[0]);
		retvalb = exec_builtin(tokens, env);
		if (retvalb == -1)
		{
			retval = file_check(tokens, env);
			pid = fork();
			if (pid == -1)
			{
				perror("Error:");
				exit(98);
			}
			else if (pid == 0)
			{
				if (retval == 0) 
					our_execve(tokens, env, tokens[0]);
				else 
					cmd_not_found_error(argv[0], filename);
			}
			else 
				wait(&status);
		}		
		free(buffer);
		free_grid(tokens, args);
		free(filename);
		free(getline_cp);
	}
	return(0);
}
