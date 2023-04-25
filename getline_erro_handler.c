#include "main.h"

void getline_error_handler(char *buffer)
{
	free(buffer);
	printf("\n");
	exit(0);
}
