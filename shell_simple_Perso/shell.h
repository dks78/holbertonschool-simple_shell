#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

/* Function prototypes */
char *read_line(void);
char **split_line(char *line);
int execute_command(char **args);
char *get_path(char *command);
void print_environment(void);

/* Global environment variable */
extern char **environ;

#endif /* SHELL_H */
