#include "main.h"

int get_prompt(void)
{
	int retval;

	retval = write(STDOUT_FILENO, "$ ", 2);

	if (retval == -1)
		exit(-1);
	return (retval);
}	
