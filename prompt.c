#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define PROMPT "$ "

/**
 * _strlen - calcule la longueur d'une chaîne de caractères
 * @str: chaîne de caractères dont la longueur est à calculer
 * Return: longueur de la chaîne
 */
unsigned int _strlen(char *str)
{
    unsigned int length = 0;

    while (str[length] != '\0')
    {
        length++;
    }

    return (length);
}

/**
 * _puts - imprime une chaîne sans ajouter de '\n'
 * @str: chaîne à imprimer
 * Return: void
 */
void _puts(char *str)
{
    unsigned int length;

    length = _strlen(str);

    write(STDOUT_FILENO, str, length);
}

/**
 * prompt - affiche le prompt si le terminal est un terminal interactif
 * @fd: descripteur de fichier
 * @buf: structure de type stat contenant des informations sur le fichier
 * Return: void
 */
void prompt(int fd, struct stat buf)
{
    fstat(fd, &buf);

    if (S_ISCHR(buf.st_mode))
    {
        _puts(PROMPT);
    }
}
