#include "main.h"
/**
 * free_fc - free memory allocated in file_check
 * @a: pointer to memory address
 * @b: pointer to mem address
 * @c: pointer to mem address
 *
 * Description: free mem malloc'd in file_check
 * Return: void
 */
void free_fc(char *a, char *b, char *c)
{
	free(a);
	free(b);
	free(c);
}
