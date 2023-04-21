#include "main.h"

int our_execve(char *tokens[], char *environ[], char *fn)
{
	tokens[0] = fn;
	execve(tokens[0], tokens, environ);
	return (-1);
}
