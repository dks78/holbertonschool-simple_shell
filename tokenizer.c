
#include "simple_shell.h" 

char **tokenize_command(char *command)
{
    char **argv;
    char *token;
    int i = 0;

    argv = malloc(sizeof(char *) * (MAX_INPUT_SIZE / 2 + 1));
    if (argv == NULL) {
        perror("malloc");
        return NULL;
    }

    token = strtok(command, " ");
    while (token != NULL) {
        argv[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    argv[i] = NULL;
    return argv;
}
