#include "main.h"
/**
 * _strdup - duplicate a string
 * @str: string to duplicate
 *
 * Return: pointer to a newly allocated mem location with duplicate
 */
char *_strdup(char *str)
{
	int len = 0, i = 0;
	char *new = NULL;

	len = _strlen(str) + 1;

	new = malloc(sizeof(char) * len);
	if (!new)
		return (NULL);

	for (i = 0; str[i]; i++)
		new[i] = str[i];
	new[i] = '\0';
	return (new);
}
