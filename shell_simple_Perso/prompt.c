#include "simple_shell.h"

/**
 * prompt - checks mode and prints prompt if in interactive mode
 * @fd: file stream
 * @buf: buffer
**/
void prompt(int fd, struct stat buf) /*ce code sert a affiché le pronmpt a*/
{
	/*fstat prend ce descripteur de fichier fd et la structure buf (de type struct stat).*/
	fstat(fd, &buf);
	/*fstat sert a récupérer des information
	d'un fichier ou d'un flux*/
	/*fd = descripteur de fstat*/
	if (S_ISCHR(buf.st_mode))/*si le descripteur correspond a un terminale afficher le prompt */
		_puts(PROMPT); 
}
/**
 * _puts - prints a string without a \n
 * @str: string to print
 * Return: void
 */
void _puts(char *str)/*affiche une chaine de charactére dans le terminale*/
{
	unsigned int length;

	length = strlen(str);

	write(STDOUT_FILENO, str, length);
}
