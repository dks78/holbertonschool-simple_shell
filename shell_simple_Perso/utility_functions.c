#include "simple_shell.h"
/*La gestion des variables d'environnement
Le traitement des options et arguments
La gestion des erreurs
C'est comme si ces fonctions donnaient à votre shell :

Les "yeux" pour lire les commandes
Le "cerveau" pour les comprendre
La capacité de "décider" comment les traiter*/
/*c'est fonction sont crusial pour le shell*/ 
/*elle serviront au terminale pour les commande cd/fil/ectt , reconnaitre les commande intégrer , sans c'est commande*/
/*le shell ne reconnaitra pas les commande comme cd exit ect */
/**
 * _strcmp - compare 2 chaine de charactéres
 * @name: name supplied by user to search fo
 * @variable: variable to compare against
 * @length: length of name
 * Return: 1 if strings are equal, -1 if they are not
 */

int _strcmp(char *name, char *variable, unsigned int length)
{
    while (*name && *variable && length--)
    {
        if (*name != *variable)
        {
            return (*name - *variable);
        }
        name++;
        variable++;
    }

    return (*name - *variable);
}



/**
 * _strncmp - comapares les premier charactére d'une chaine
 * @name: name supplied by user to search for
 * @variable: variable to compare against
 * @length: length to compare up to
 * Return: 1 if strings are equal, -1 if they are not
 */
int _strncmp(char *name, char *variable, unsigned int length)
{
	unsigned int i;

	i = 0;
	while (i < length)
	{
		if (name[i] != variable[i])
			return (-1);
		i++;
	}
	return (1);
}
/**
 * *_strcpy - copies string pointed to by src to the buffer pointed to dest
 * @dest: string destination
 * @src: string source
 * Return: the pointer to dest
 */
/*C'est utile dans votre shell pour :
Copier des commandes
Dupliquer des chemins
Sauvegarder temporairement des chaînes
Manipuler des variables d'environnement
*/
char *_strcpy(char *dest, char *src)
{
   int i;


    for (i = 0; src[i] != '\0'; i++) {
    dest[i] = src[i];
}
    dest[i] = '\0';

    return dest;
}

/**
 * _strlen - returns the length of a string
 * @s: string to be evaluated
 * Return: length of string
 */

int _strlen(char *s)
/*
Vérifier la taille des commandes
Allouer la bonne quantité de mémoire
Comparer les longueurs des chaînes
Valider les entrées utilisateur
*/
{

    int len = 0;

    while (s[len] != '\0')
    {
        len++;
    }
    return (len);
}
