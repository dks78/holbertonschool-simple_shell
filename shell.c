#include "simple_shell.h"

/* Fonction pour afficher les erreurs */
void handle_error(char *command)
{
    perror(command);
}

/* Fonction pour exécuter la commande */
int execute_command(char *command, char **args)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return -1;
    }
    if (pid == 0) {
        /* Exécution de la commande */
        if (execve(command, args, NULL) == -1) {
            perror("execve");
            exit(EXIT_FAILURE);
        }
    } else {
        /* Parent attend la fin de l'exécution de l'enfant */
        waitpid(pid, &status, 0);
    }

    return 0;
}

/* Fonction pour lire l'entrée de l'utilisateur */
char *read_input(void)
{
    char *input = NULL;
    size_t len = 0;

    printf("$ ");
    getline(&input, &len, stdin);

    return input;
}

/* Fonction pour analyser l'entrée et la diviser en arguments */
char **parse_input(char *input)
{
    int bufsize = 64;
    int position = 0;
    char **args = malloc(bufsize * sizeof(char *));
    char *token;

    if (!args) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    token = strtok(input, " \n");
    while (token != NULL) {
        args[position] = token;
        position++;

        if (position >= bufsize) {
            bufsize += 64;
            args = realloc(args, bufsize * sizeof(char *));
            if (!args) {
                perror("realloc");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, " \n");
    }
    args[position] = NULL;
    return args;
}

/* Fonction pour libérer la mémoire allouée pour les arguments */
void free_arguments(char **args)
{
    free(args);
}

/* Fonction pour afficher le prompt */
void prompt(void)
{

    printf("$ ");
}
