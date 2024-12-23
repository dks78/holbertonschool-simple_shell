#include "simple_shell.h"
#include <stdio.h>  /* Pour printf, perror, etc. */
#include <stdlib.h> /* Pour exit(), malloc(), etc. */
#include <unistd.h> /* Pour execve(), fork(), etc. */
#include <sys/wait.h> /* Pour wait() */
#include <sys/stat.h> /* Pour fstat() */

#define PROMPT "$ "

/**
 * main - point d'entrée du shell
 *
 * Return: 0 en cas de succès
 */
int main(void)
{
    char *input = NULL;    /* Chaîne pour stocker l'entrée utilisateur */
    size_t len = 0;        /* Taille du buffer pour getline */
    ssize_t nread;         /* Nombre de caractères lus par getline */
    char **tokens;         /* Tableau des tokens après le découpage de la commande */
    pid_t pid;             /* Process ID pour fork */
    int status;            /* Statut pour wait() */
    struct stat buf;       /* Structure stat pour les informations de fichier */

    /* Boucle principale du shell */
    while (1)
    {
        fstat(STDIN_FILENO, &buf); /* Initialiser buf avec les informations sur stdin */
        prompt(STDIN_FILENO, buf); /* Afficher le prompt */

        nread = getline(&input, &len, stdin); /* Lire l'entrée utilisateur */

        /* Si EOF (Ctrl+D), quitter le shell */
        if (nread == -1)
        {
            if (feof(stdin)) /* Si EOF atteint (Ctrl+D) */
            {
                free(input);  /* Libérer la mémoire allouée */
                printf("\n");
                exit(0); /* Quitter le shell */
            }
            else
            {
                perror("getline"); /* Erreur lors de la lecture */
                exit(1);
            }
        }

        /* Supprimer le '\n' de la fin de l'entrée (si présent) */
        input[nread - 1] = '\0';

        /* Tokeniser l'entrée utilisateur */
        tokens = tokenizer(input);
        if (tokens == NULL)
        {
            free(input); /* Libérer la mémoire allouée */
            continue;     /* Si aucune commande, recommencer */
        }

        /* Fork pour créer un processus enfant */
        pid = fork();
        if (pid == -1)
        {
            perror("fork"); /* Erreur lors du fork */
            free(input);
            free(tokens);
            exit(1);
        }

        if (pid == 0) /* Code pour le processus enfant */
        {
            /* Exécuter la commande avec execve */
            if (execve(tokens[0], tokens, NULL) == -1)
            {
                perror("execve"); /* Erreur d'exécution de la commande */
                free(input);
                free(tokens);
                exit(1);
            }
        }
        else /* Code pour le processus parent */
        {
            /* Attendre que le processus enfant se termine */
            wait(&status);
        }

        /* Libérer la mémoire allouée pour les tokens et l'entrée */
        free(tokens);
    }

    /* Libérer la mémoire allouée pour l'entrée (en cas de sortie anticipée) */
    free(input);
    return (0);
}
