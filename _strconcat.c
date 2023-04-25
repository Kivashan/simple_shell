#include "main.h"

/**
 * stringconcat - concatenates two strings
 * @str1: pointer tothe first string
 * @str2: pointer to the second string
 *
 * Return: pointer to anewly malloc'ed string
 */

char *_strconcat(char *str1, char *str2)
{
	int l1, l2;
	char *new = NULL;
	int i = 0, j = 0;

	l1 = _strlen(str1);
	l2 = _strlen(str2);

	new = malloc(sizeof(char) * (l1 + l2 + 2));

	for (i = 0; str1[i]; i++)
		new[i] = str1[i];

	new[i] = '/';
	i++;

	for (j = 0; str2[j]; j++)
		new[i + j] = str2[j];
	new[i + j] = '\0';
	return (new);
}
