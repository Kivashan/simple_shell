#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>

int _putchar(char);
int _puts(char *);
int stringlen(char *);
char *stringcpy(char *);
int no_of_args(char *, char *);
char *stringconcat(char *str1, char *str2);
char *getpath(char **envr);
void get_prompt(void);

char **the_tokeniser(char *, char *);
int our_execve(char **, char **, char *);

/* functions to free malloc'ed strings */
void free_grid(char **grid);
void free_fc(char *, char *, char *);
void free_ff(char**, char *, char *);

void get_filename(char *cp_cmd, char *filename, int len, int *pos);
int file_check(char *tokens[], char *environ[], char **fn);
/*file_finder - similar to file_check but handles relative path*/
char **file_finder(char *tokens[], char *environ[], char **fn);
/* functions handling error messages*/
void cmd_not_found_error(char *argv, char *token);
/*inbuilt*/
void exec_builtin(char **tok);
void our_exit(char **tok);
void print_env(char **tok);
/**
 * struct get_inbuilt - holds a string and a function pointer
 * @cmd: command
 * @func: pointer to function corresponding to command
 */
typedef struct get_inbuilt
{
	char *cmd;
	void (*func)(char **tokens);
} get_func;

int stringcomp(char *str1, char *str2);
void sig_handler(int sig);
#endif
