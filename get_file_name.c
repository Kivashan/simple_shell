#include "main.h"

/**
 * get_filename - gets the filename at the end of the absolute path
 * @cp_cmd: a String
 * @filename: a string
 * @len: length of cp_cmd
 * @pos: pointer to the position of filename
 *
 * @Return: 
 */

void get_filename(char *cp_cmd, char *filename, int len, int *pos)
{
	if (cp_cmd[len] != '\0')
	{
		filename[*pos] = cp_cmd[len];
		*pos = *pos + 1;
		get_filename(cp_cmd, filename, ++len, pos);
	}
}
