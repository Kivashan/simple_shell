#include "main.h"

void free_ff(char **a, char *b, char *c)
{
	int i = 0;

	for (i = 0; a[i]; i++)
	{
		free(a[i]);
	}
	free(a);
	free(b);
	free(c);
}
