#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>

int _putchar(char);
int _puts(char *);
void get_prompt(void);
char *stringconcat(char *str1, char *str2);
char *stringcpy(char *str);
int stringlen(char *str);

#endif
