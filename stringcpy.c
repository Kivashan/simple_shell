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
	char *newString;

	if (!str)
		return (NULL);

	len = stringlen(str);
	newString = malloc(sizeof(char) * (len + 1));
	
	if (!newString)
		return (NULL);
	while (str[i])
	{
		newString[i] = str[i];
		i++;
	}
	
	return (newString);
}
