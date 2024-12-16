#ifndef MAIN_H
#define MAIN_H

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>  

/**
 * main - Fonction principale du shell
 *
 * Return: Toujours 0.
 */
int main(void);

/**
 * execute_command - Exécute la commande donnée par l'utilisateur.
 * @line: La ligne de commande entrée par l'utilisateur.
 */
void execute_command(char *line);

/**
 * handle_error - Affiche un message d'erreur si la commande n'est pas trouvée.
 * @command: La commande qui a échoué.
 */
void handle_error(char *command);

/**
 * is_empty_line - Vérifie si la ligne entrée par l'utilisateur est vide.
 * @line: La ligne de commande.
 * Return: 1 si la ligne est vide, 0 sinon.
 */
int is_empty_line(char *line);

/**
 * prompt - Affiche le prompt à chaque demande de commande.
 */
void prompt(void);

#endif /* MAIN_H */
