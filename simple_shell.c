#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_INPUT_SIZE 1024

/**
 * main - Fonction principale pour démarrer le shell
 *
 * Return: 0 (Success)
 */
int main(void)
{
    char *command = NULL;
    char *argv[2];  /* Déclaration du tableau d'arguments pour une commande simple */
    size_t len = 0;
    ssize_t nread;
    pid_t pid;
    int status;

    while (1)
    {
        /* Afficher le prompt */
        printf("($) ");
        
        /* Obtenir l'entrée de l'utilisateur */
        nread = getline(&command, &len, stdin);
        
        /* Gérer la fin de fichier (Ctrl+D) */
        if (nread == -1)
        {
            if (feof(stdin))
            {
                printf("\n");
                break;  /* Quitter si Ctrl+D est pressé */
            }
            else
            {
                perror("getline");
                break;
            }
        }

        /* Enlever le caractère de nouvelle ligne de la commande */
        command[nread - 1] = '\0';

        /* Si l'utilisateur entre une commande vide, ignorer */
        if (command[0] == '\0')
        {
            continue;
        }

        /* Initialiser le tableau argv après avoir récupéré la commande */
        argv[0] = command;
        argv[1] = NULL;  /* Terminer le tableau avec NULL */

        /* Création d'un processus enfant pour exécuter la commande */
        pid = fork();
        if (pid == -1)  /* Erreur de fork */
        {
            perror("fork");
            exit(1);
        }

        if (pid == 0)  /* Code pour le processus enfant */
        {
            /* Exécution de la commande avec execve */
            if (execve(command, argv, NULL) == -1)
            {
                perror("./hsh");
                exit(1);
            }
        }
        else  /* Code pour le processus parent */
        {
            /* Attendre la fin du processus enfant */
            wait(&status);
        }
    }

    /* Libérer la mémoire allouée pour la commande */
    free(command);
    return (0);
}
