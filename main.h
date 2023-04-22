#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

int _putchar(char);
int _puts(char *);
int stringlen(char *);
char *stringcpy(char *);
int no_of_args(char *, char *);
char *stringconcat(char *str1, char *str2);
char *getpath(char **envr);
void get_prompt();

char **the_tokeniser(char *, char *);
int our_execve(char **, char **, char *);

/* functions to free malloc'ed strings */
void free_grid(char **grid);
void free_fc(char *, char *, char *);
void free_ff(char**, char *, char *);

void get_filename(char *cp_cmd, char *filename, int len, int *pos);
int file_check(char *tokens[], char *environ[], char **fn);
ssize_t our_getline(char **lineptr, size_t *n, int stream);
/*file_finder - similar to file_check but handles relative path*/
char **file_finder(char *tokens[], char *environ[], char **fn);
/* functions handling error messages*/
void cmd_not_found_error(char *argv, char *token);

#endif
