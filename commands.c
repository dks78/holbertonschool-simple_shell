#include <unistd.h>
#include <stdlib.h>
#include "simple_shell.h" 
void handle_command(char *command)
{
    char **argv;
    pid_t pid;
    int status;

    command[strcspn(command, "\n")] = '\0';  /* Supprimer le saut de ligne */
    argv = tokenize_command(command);  /* Diviser la commande en arguments */
    if (argv == NULL)
        return;

    if (strcmp(argv[0], "exit") == 0) {
        free(argv);
        exit(0);
    }

    if (strcmp(argv[0], "cd") == 0) {
        if (argv[1] == NULL) {
            fprintf(stderr, "cd: missing argument\n");
        } else {
            if (chdir(argv[1]) != 0) {
                perror("cd");
            }
        }
        free(argv);
        return;
    }

    pid = fork();
    if (pid == 0) {
        if (execve(argv[0], argv, NULL) == -1) {
            perror("./hsh");
            free(argv);
            exit(1);
        }
    } else {
        wait(&status);
    }
    free(argv);
}
