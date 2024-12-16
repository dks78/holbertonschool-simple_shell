#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h> 
/* Prototypes des fonctions */
void handle_error(char *command);
int execute_command(char *command, char **args);
char *read_input(void);
char **parse_input(char *input);
void free_arguments(char **args);
void prompt(void);

#endif /* MAIN_H */
