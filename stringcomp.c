#include "main.h"
/**
 * stringcomp - compares two strings
 * @str1: first string
 * @str2: second string
 *
 * Description: compare similarity of two strings
 * Return: 0 if strings are equaul, -1 otherwise
 */
int stringcomp(char *str1, char *str2)
{
	int i = 0;

	if (!str1 || !str2)
		return (-1);
	if (_strlen(str1) != _strlen(str2))
		return (-1);
	while (str1[i] &&  str2[i])
	{
		if (str1[i] != str2[i])
			return (-1);
		i++;
	}
	return (0);
}
