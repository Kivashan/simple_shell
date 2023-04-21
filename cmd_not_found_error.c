#include "main.h"

/**
 * cmd_not_found_error - prints error message on stdout
 * @token: the command entered on the cmdline
 *
 * Return: Void
 */

void cmd_not_found_error(char *argv, char *token)
{
	_puts(argv);
	_puts(": 1: ");
	_puts(token);
	_puts(": not found\n");
}
