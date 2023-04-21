#include "main.h"

int _puts(char *str)
{
	int i = 0;

	if (!str)
		return (-1);

	while(str[i])
	{
		_putchar(str[i]);
		i++;
	}

	return (i);
}
