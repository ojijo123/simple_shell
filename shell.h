#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdbool.h>

extern char **environ;

int main(int ac, char **argv[]);
void env_built_in(char *first1);
void tokenization(char *formats, char **user_inputs, char **argument);
void path_handler(char *first_argument, char **arguments, char **argv_0);
void execute_command(char *buffer, char **string, char **arg);
void command(char *buffer);
void exit_built_in(char *first);

#endif
