#include "main.h"

/**
 * stringcpy - copies the contents of str into a new string
 * @str: string to be copied
 *
 * Return: Returns a pointer to the newly malloc'ed string
 */

char *stringcpy(char *str)
{
	int len = 0, i = 0;
	char *new;

	if (!str)
		return (NULL);

	len = stringlen(str);
	new = malloc(sizeof(char) * (len + 1));
	
	if (!new)
		return (NULL);
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	
	return (new);
}
