#include "main.h"
/**
 * free_ff - free space malloc'd in file_finder
 * @a: pointer to a memory address
 * @b: pointer to a mem address
 * @c: pointer to mem address
 *
 * Description: free memory
 * Return: void
 */
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
