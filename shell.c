#include "main.h"

void execute_command(char *line)
{
    char *command[2];
    command[0] = line;
    command[1] = NULL;

    if (execve(command[0], command, NULL) == -1) {
        handle_error(line);
    }
}

/**
 * handle_error - Affiche un message d'erreur si la commande n'est pas trouvée.
 * @command: La commande qui a échoué.
 */
void handle_error(char *command)
{
    perror(command);
}

/**
 * is_empty_line - Vérifie si la ligne entrée est vide.
 * @line: La ligne de commande.
 * Return: 1 si vide, 0 sinon.
 */
int is_empty_line(char *line)
{
    return (strlen(line) == 0);
}

/**
 * prompt - Affiche le prompt "#cisfun$ ".
 */
void prompt(void)
{
    printf("#cisfun$ ");
}